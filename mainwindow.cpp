#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial(new QSerialPort(this))
{
    ui->setupUi(this);
    setupUI();
    setupChart();
    setupSerialControls();
    updatePortList();
}

MainWindow::~MainWindow() {
    if (serial->isOpen())
        serial->close();
    delete ui;
}

void MainWindow::setupUI() {
    // Obtener referencias a los widgets del archivo .ui
    portComboBox = ui->portComboBox;
    baudRateComboBox = ui->baudRateComboBox;
    dataBitsComboBox = ui->dataBitsComboBox;
    parityComboBox = ui->parityComboBox;
    stopBitsComboBox = ui->stopBitsComboBox;
    maxPointsSpinBox = ui->maxPointsSpinBox;
    windowSizeSpinBox = ui->windowSizeSpinBox;
    minRangeSpinBox = ui->minRangeSpinBox;
    maxRangeSpinBox = ui->maxRangeSpinBox;
    connectButton = ui->connectButton;
    disconnectButton = ui->disconnectButton;
    refreshButton = ui->refreshButton;
    clearButton = ui->clearButton;
    statusLabel = ui->statusLabel;

    // Configurar valores iniciales
    maxPointsSpinBox->setRange(100, 10000);
    maxPointsSpinBox->setValue(1000);

    windowSizeSpinBox->setRange(100, 5000);
    windowSizeSpinBox->setValue(1000);

    minRangeSpinBox->setRange(0, 10000);
    minRangeSpinBox->setValue(0);

    maxRangeSpinBox->setRange(0, 10000);
    maxRangeSpinBox->setValue(4095);

    // Conectar señales
    connect(connectButton, &QPushButton::clicked, this, &MainWindow::connectSerial);
    connect(disconnectButton, &QPushButton::clicked, this, &MainWindow::disconnectSerial);
    connect(refreshButton, &QPushButton::clicked, this, &MainWindow::refreshPorts);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearChart);

    connect(maxPointsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            [this](int value) { maxPoints = value; });
    connect(windowSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            [this](int value) { windowSize = value; });
    connect(minRangeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            [this](int value) { axisY->setMin(value); });
    connect(maxRangeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            [this](int value) { axisY->setMax(value); });

    // Estado inicial
    disconnectButton->setEnabled(false);
    statusLabel->setText("Desconectado");
}

void MainWindow::setupChart() {
    // Configuración del gráfico
    series = new QLineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Datos Serial en Tiempo Real");

    axisX = new QValueAxis();
    axisX->setRange(0, windowSize);
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Tiempo");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0, 4095);
    axisY->setTitleText("Valor");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Agregar el gráfico al widget contenedor del .ui
    QVBoxLayout *chartLayout = new QVBoxLayout(ui->chartWidget);
    chartLayout->addWidget(chartView);
    ui->chartWidget->setLayout(chartLayout);
}

void MainWindow::setupSerialControls() {
    // Configurar baudrates
    QStringList baudRates = {"1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200"};
    baudRateComboBox->addItems(baudRates);
    baudRateComboBox->setCurrentText("9600");

    // Configurar bits de datos
    QStringList dataBits = {"5", "6", "7", "8"};
    dataBitsComboBox->addItems(dataBits);
    dataBitsComboBox->setCurrentText("8");

    // Configurar paridad
    QStringList parity = {"None", "Even", "Odd", "Space", "Mark"};
    parityComboBox->addItems(parity);
    parityComboBox->setCurrentText("None");

    // Configurar bits de parada
    QStringList stopBits = {"1", "1.5", "2"};
    stopBitsComboBox->addItems(stopBits);
    stopBitsComboBox->setCurrentText("1");
}

void MainWindow::updatePortList() {
    portComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        portComboBox->addItem(info.portName() + " - " + info.description());
    }
}

void MainWindow::refreshPorts() {
    updatePortList();
}

void MainWindow::connectSerial() {
    if (portComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Error", "No hay puertos disponibles");
        return;
    }

    // Obtener nombre del puerto
    QString portName = portComboBox->currentText().split(" - ").first();

    // Configurar puerto serial
    serial->setPortName(portName);
    serial->setBaudRate(baudRateComboBox->currentText().toInt());

    // Configurar bits de datos
    QSerialPort::DataBits dataBits = static_cast<QSerialPort::DataBits>(dataBitsComboBox->currentText().toInt());
    serial->setDataBits(dataBits);

    // Configurar paridad
    QSerialPort::Parity parity;
    QString parityText = parityComboBox->currentText();
    if (parityText == "None") parity = QSerialPort::NoParity;
    else if (parityText == "Even") parity = QSerialPort::EvenParity;
    else if (parityText == "Odd") parity = QSerialPort::OddParity;
    else if (parityText == "Space") parity = QSerialPort::SpaceParity;
    else parity = QSerialPort::MarkParity;
    serial->setParity(parity);

    // Configurar bits de parada
    QSerialPort::StopBits stopBits;
    QString stopBitsText = stopBitsComboBox->currentText();
    if (stopBitsText == "1") stopBits = QSerialPort::OneStop;
    else if (stopBitsText == "1.5") stopBits = QSerialPort::OneAndHalfStop;
    else stopBits = QSerialPort::TwoStop;
    serial->setStopBits(stopBits);

    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadOnly)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
        connectButton->setEnabled(false);
        disconnectButton->setEnabled(true);
        statusLabel->setText("Conectado a " + portName);
        qDebug() << "Puerto abierto correctamente:" << portName;
    } else {
        QMessageBox::critical(this, "Error", "Error al abrir el puerto: " + serial->errorString());
        statusLabel->setText("Error de conexión");
    }
}

void MainWindow::disconnectSerial() {
    if (serial->isOpen()) {
        serial->close();
        disconnect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    }

    connectButton->setEnabled(true);
    disconnectButton->setEnabled(false);
    statusLabel->setText("Desconectado");
}

void MainWindow::clearChart() {
    series->clear();
    x = 0;
    axisX->setRange(0, windowSize);
}

void MainWindow::readSerialData() {
    QByteArray data = serial->readAll();
    buffer.append(data);

    int index;
    while ((index = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(index).trimmed();
        buffer.remove(0, index + 1);

        bool ok;
        int value = line.toInt(&ok);
        if (ok) {
            qDebug() << "Valor recibido:" << value;
            series->append(x++, value);

            if (series->count() > maxPoints) {
                QList<QPointF> puntos = series->points();
                puntos.removeFirst();
                series->replace(puntos);
            }

            if (x > windowSize)
                axisX->setRange(x - windowSize, x);
            else
                axisX->setRange(0, windowSize);
        } else {
            qDebug() << "Error de conversión para:" << line;
        }
    }
}

void MainWindow::updateSerialSettings() {
    // Esta función se puede usar para actualizar configuraciones
    // cuando cambien los valores en los controles de la UI

    // Ejemplo de implementación:
    if (serial->isOpen()) {
        // Si el puerto está abierto, mostrar advertencia sobre cambios
        QMessageBox::information(this, "Información",
                                 "Los cambios en la configuración serial se aplicarán en la próxima conexión.");
    }

    // Aquí puedes agregar lógica adicional si necesitas
    // actualizar algo cuando cambien las configuraciones
}
