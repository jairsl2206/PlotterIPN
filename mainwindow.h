#include <QMainWindow>
#include <QSerialPort>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray buffer;

    QChart *chart;
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;

    int x = 0;
};


