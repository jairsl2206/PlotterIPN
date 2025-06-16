#define private public
#include "../mainwindow.h"
#undef private
#include <QtTest/QtTest>
#include <cmath>

class TestFFT : public QObject {
    Q_OBJECT
private slots:
    void fftDetectsSine();
};

void TestFFT::fftDetectsSine() {
    MainWindow w;
    QVector<double> samples;
    int N = 8;
    for (int n = 0; n < N; ++n) {
        samples.append(std::sin(2 * 3.14159265358979323846 * n / N));
    }
    QVector<double> mags = w.computeFFT(samples);
    int maxIndex = 0;
    double maxVal = mags[0];
    for (int i = 1; i < mags.size(); ++i) {
        if (mags[i] > maxVal) {
            maxVal = mags[i];
            maxIndex = i;
        }
    }
    QVERIFY(maxIndex == 1 || maxIndex == N - 1);
}

QTEST_MAIN(TestFFT)
#include "test_fft.moc"
