#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial(new QSerialPort(this))
{
    ui->setupUi(this);

    serial->setPortName("COM3");  // <-- Ajusta esto al puerto de tu STM32
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    //Configuración del Plot
    series = new QLineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    axisX = new QValueAxis();
    axisX->setRange(0, 100);
    axisX->setLabelFormat("%d");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0, 4095);  // Ajusta según el rango de tu señal
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);


    if (serial->open(QIODevice::ReadOnly)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
        qDebug() << "Puerto abierto correctamente.";
        qDebug() << "Puerto COM: " << serial->portName();
    } else {
        qDebug() << "Error al abrir el puerto:" << serial->errorString();
    }
}

MainWindow::~MainWindow() {
    if (serial->isOpen())
        serial->close();
    delete ui;
}

void MainWindow::readSerialData() {
    QByteArray data = serial->readAll();
    buffer.append(data);

    int index;
    while ((index = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(index).trimmed();  // quita \r si existe
        buffer.remove(0, index + 1);

        if (line.startsWith("ADC:")) {
            line = line.mid(4);  // elimina "ADC:"
        }

        bool ok;
        int value = line.toInt(&ok);
        if (ok) {
            qDebug() << "Valor recibido:" << value;
            series->append(x++, value);

            const int maxPoints = 1000;
            if (series->count() > maxPoints) {
                QList<QPointF> puntos = series->points();
                puntos.removeFirst();
                series->replace(puntos);
            }

            int ventana = 1000;
            if (x > ventana)
                axisX->setRange(x - ventana, x);
            else
                axisX->setRange(0, ventana);
        } else {
            qDebug() << "Error de conversión para:" << line;
        }
    }
}
