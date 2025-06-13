#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();
    void connectSerial();
    void disconnectSerial();
    void updateSerialSettings();
    void refreshPorts();
    void clearChart();


private:
    void setupUI();
    void setupChart();
    void setupSerialControls();
    void updatePortList();

    Ui::MainWindow *ui;

    // Serial communication
    QSerialPort *serial;
    QByteArray buffer;

    // Chart components
    QList<QLineSeries *> seriesList;
    QChart *chart;
    QChartView *chartView;
    QValueAxis *axisX;
    QValueAxis *axisY;

    // Data management
    int x = 0;
    int maxPoints = 1000;
    int windowSize = 1000;
    int channelCount = 0;

    // UI Controls (accessible from .ui file)
    QComboBox *portComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QSpinBox *maxPointsSpinBox;
    QSpinBox *windowSizeSpinBox;
    QSpinBox *minRangeSpinBox;
    QSpinBox *maxRangeSpinBox;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *refreshButton;
    QPushButton *clearButton;
    QLabel *statusLabel;
};




#endif // MAINWINDOW_H
