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
#include <QQueue>
#include <QList>
#include <QVector>

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
    void updateFFTView();


private:
    void setupUI();
    void setupChart();
    QVector<double> computeFFT(const QVector<double> &samples);
    void setupSerialControls();
    void updatePortList();
    void adjustChannelCount(int newCount);

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
    QLineSeries *fftSeries;
    QChart *fftChart;
    QChartView *fftChartView;
    QValueAxis *fftAxisX;
    QValueAxis *fftAxisY;

    enum class FilterType { None, MovingAverage };
    FilterType filterType = FilterType::None;
    int filterWindowSize = 1;
    QList<QQueue<int>> filterBuffers;

    // Data management
    int x = 0;
    int maxPoints = 1000;
    int windowSize = 1000;
    int channelCount = 0;
    QVector<double> samplesBuffer;

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
    QComboBox *filterTypeComboBox;
    QSpinBox *filterSizeSpinBox;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *refreshButton;
    QPushButton *clearButton;
    QLabel *statusLabel;
};




#endif // MAINWINDOW_H
