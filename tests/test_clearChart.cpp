#define private public
#include "../mainwindow.h"
#undef private
#include <QtTest/QtTest>

class TestClearChart : public QObject {
    Q_OBJECT
private slots:
    void clearChartResets();
};

void TestClearChart::clearChartResets() {
    MainWindow w;
    // create a series and attach to chart axes
    QLineSeries *series = new QLineSeries();
    w.chart->addSeries(series);
    series->attachAxis(w.axisX);
    series->attachAxis(w.axisY);
    w.seriesList.append(series);

    series->append(0, 1);
    series->append(1, 2);
    w.x = 2;
    w.axisX->setRange(1, 3);

    w.clearChart();

    QCOMPARE(series->count(), 0);
    QCOMPARE(w.x, 0);
    QCOMPARE(w.axisX->min(), 0.0);
    QCOMPARE(w.axisX->max(), double(w.windowSize));
}

QTEST_MAIN(TestClearChart)
#include "test_clearChart.moc"
