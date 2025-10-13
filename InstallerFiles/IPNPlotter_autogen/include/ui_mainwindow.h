/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QGroupBox *controlsGroupBox;
    QVBoxLayout *verticalLayout_controls;
    QGroupBox *serialGroupBox;
    QGridLayout *gridLayout_serial;
    QLabel *portLabel;
    QComboBox *portComboBox;
    QPushButton *refreshButton;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsComboBox;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QGroupBox *chartGroupBox;
    QGridLayout *gridLayout_chart;
    QLabel *maxPointsLabel;
    QSpinBox *maxPointsSpinBox;
    QLabel *windowSizeLabel;
    QSpinBox *windowSizeSpinBox;
    QLabel *minRangeLabel;
    QSpinBox *minRangeSpinBox;
    QLabel *maxRangeLabel;
    QSpinBox *maxRangeSpinBox;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer;
    QLabel *statusLabel;
    QWidget *chartWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        controlsGroupBox = new QGroupBox(centralwidget);
        controlsGroupBox->setObjectName("controlsGroupBox");
        controlsGroupBox->setMaximumWidth(300);
        verticalLayout_controls = new QVBoxLayout(controlsGroupBox);
        verticalLayout_controls->setObjectName("verticalLayout_controls");
        serialGroupBox = new QGroupBox(controlsGroupBox);
        serialGroupBox->setObjectName("serialGroupBox");
        gridLayout_serial = new QGridLayout(serialGroupBox);
        gridLayout_serial->setObjectName("gridLayout_serial");
        portLabel = new QLabel(serialGroupBox);
        portLabel->setObjectName("portLabel");

        gridLayout_serial->addWidget(portLabel, 0, 0, 1, 1);

        portComboBox = new QComboBox(serialGroupBox);
        portComboBox->setObjectName("portComboBox");

        gridLayout_serial->addWidget(portComboBox, 0, 1, 1, 1);

        refreshButton = new QPushButton(serialGroupBox);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setMaximumWidth(30);

        gridLayout_serial->addWidget(refreshButton, 0, 2, 1, 1);

        baudRateLabel = new QLabel(serialGroupBox);
        baudRateLabel->setObjectName("baudRateLabel");

        gridLayout_serial->addWidget(baudRateLabel, 1, 0, 1, 1);

        baudRateComboBox = new QComboBox(serialGroupBox);
        baudRateComboBox->setObjectName("baudRateComboBox");

        gridLayout_serial->addWidget(baudRateComboBox, 1, 1, 1, 2);

        dataBitsLabel = new QLabel(serialGroupBox);
        dataBitsLabel->setObjectName("dataBitsLabel");

        gridLayout_serial->addWidget(dataBitsLabel, 2, 0, 1, 1);

        dataBitsComboBox = new QComboBox(serialGroupBox);
        dataBitsComboBox->setObjectName("dataBitsComboBox");

        gridLayout_serial->addWidget(dataBitsComboBox, 2, 1, 1, 2);

        parityLabel = new QLabel(serialGroupBox);
        parityLabel->setObjectName("parityLabel");

        gridLayout_serial->addWidget(parityLabel, 3, 0, 1, 1);

        parityComboBox = new QComboBox(serialGroupBox);
        parityComboBox->setObjectName("parityComboBox");

        gridLayout_serial->addWidget(parityComboBox, 3, 1, 1, 2);

        stopBitsLabel = new QLabel(serialGroupBox);
        stopBitsLabel->setObjectName("stopBitsLabel");

        gridLayout_serial->addWidget(stopBitsLabel, 4, 0, 1, 1);

        stopBitsComboBox = new QComboBox(serialGroupBox);
        stopBitsComboBox->setObjectName("stopBitsComboBox");

        gridLayout_serial->addWidget(stopBitsComboBox, 4, 1, 1, 2);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        connectButton = new QPushButton(serialGroupBox);
        connectButton->setObjectName("connectButton");

        horizontalLayout_buttons->addWidget(connectButton);

        disconnectButton = new QPushButton(serialGroupBox);
        disconnectButton->setObjectName("disconnectButton");

        horizontalLayout_buttons->addWidget(disconnectButton);


        gridLayout_serial->addLayout(horizontalLayout_buttons, 5, 0, 1, 3);


        verticalLayout_controls->addWidget(serialGroupBox);

        chartGroupBox = new QGroupBox(controlsGroupBox);
        chartGroupBox->setObjectName("chartGroupBox");
        gridLayout_chart = new QGridLayout(chartGroupBox);
        gridLayout_chart->setObjectName("gridLayout_chart");
        maxPointsLabel = new QLabel(chartGroupBox);
        maxPointsLabel->setObjectName("maxPointsLabel");

        gridLayout_chart->addWidget(maxPointsLabel, 0, 0, 1, 1);

        maxPointsSpinBox = new QSpinBox(chartGroupBox);
        maxPointsSpinBox->setObjectName("maxPointsSpinBox");

        gridLayout_chart->addWidget(maxPointsSpinBox, 0, 1, 1, 1);

        windowSizeLabel = new QLabel(chartGroupBox);
        windowSizeLabel->setObjectName("windowSizeLabel");

        gridLayout_chart->addWidget(windowSizeLabel, 1, 0, 1, 1);

        windowSizeSpinBox = new QSpinBox(chartGroupBox);
        windowSizeSpinBox->setObjectName("windowSizeSpinBox");

        gridLayout_chart->addWidget(windowSizeSpinBox, 1, 1, 1, 1);

        minRangeLabel = new QLabel(chartGroupBox);
        minRangeLabel->setObjectName("minRangeLabel");

        gridLayout_chart->addWidget(minRangeLabel, 2, 0, 1, 1);

        minRangeSpinBox = new QSpinBox(chartGroupBox);
        minRangeSpinBox->setObjectName("minRangeSpinBox");

        gridLayout_chart->addWidget(minRangeSpinBox, 2, 1, 1, 1);

        maxRangeLabel = new QLabel(chartGroupBox);
        maxRangeLabel->setObjectName("maxRangeLabel");

        gridLayout_chart->addWidget(maxRangeLabel, 3, 0, 1, 1);

        maxRangeSpinBox = new QSpinBox(chartGroupBox);
        maxRangeSpinBox->setObjectName("maxRangeSpinBox");

        gridLayout_chart->addWidget(maxRangeSpinBox, 3, 1, 1, 1);

        clearButton = new QPushButton(chartGroupBox);
        clearButton->setObjectName("clearButton");

        gridLayout_chart->addWidget(clearButton, 4, 0, 1, 2);


        verticalLayout_controls->addWidget(chartGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_controls->addItem(verticalSpacer);

        statusLabel = new QLabel(controlsGroupBox);
        statusLabel->setObjectName("statusLabel");

        verticalLayout_controls->addWidget(statusLabel);


        horizontalLayout_main->addWidget(controlsGroupBox);

        chartWidget = new QWidget(centralwidget);
        chartWidget->setObjectName("chartWidget");

        horizontalLayout_main->addWidget(chartWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PlotterIPN - Graficador Serial", nullptr));
        controlsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Configuraci\303\263n", nullptr));
        serialGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Puerto Serial", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Puerto:", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("MainWindow", "Baudrate:", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("MainWindow", "Bits datos:", nullptr));
        parityLabel->setText(QCoreApplication::translate("MainWindow", "Paridad:", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("MainWindow", "Bits parada:", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        chartGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Configuraci\303\263n del Gr\303\241fico", nullptr));
        maxPointsLabel->setText(QCoreApplication::translate("MainWindow", "M\303\241x. puntos:", nullptr));
        windowSizeLabel->setText(QCoreApplication::translate("MainWindow", "Ventana:", nullptr));
        minRangeLabel->setText(QCoreApplication::translate("MainWindow", "Rango m\303\255n:", nullptr));
        maxRangeLabel->setText(QCoreApplication::translate("MainWindow", "Rango m\303\241x:", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Limpiar Gr\303\241fico", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Estado: Desconectado", nullptr));
        statusLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { padding: 5px; background-color: #f0f0f0; border: 1px solid #ccc; }", nullptr));
        chartWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "QWidget { border: 1px solid #ccc; }", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
