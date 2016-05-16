/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *Regresseurs;
    QToolButton *Import_X;
    QProgressBar *progressBar;
    QLabel *label;
    QToolButton *Import_Y;
    QPlainTextEdit *Reponses;
    QToolButton *Import_Test;
    QPlainTextEdit *Fichier_test;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Lancer;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *Pred;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *Export_Params;
    QLabel *label_9;
    QCheckBox *Probas_Seuil;
    QCheckBox *Trier;
    QComboBox *Ordre;
    QDoubleSpinBox *seuil;
    QPushButton *About_Button;
    QSpinBox *individu_i;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 455);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Regresseurs = new QPlainTextEdit(centralWidget);
        Regresseurs->setObjectName(QString::fromUtf8("Regresseurs"));
        Regresseurs->setGeometry(QRect(100, 50, 711, 41));
        Import_X = new QToolButton(centralWidget);
        Import_X->setObjectName(QString::fromUtf8("Import_X"));
        Import_X->setGeometry(QRect(820, 50, 31, 41));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 260, 551, 31));
        progressBar->setValue(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 260, 81, 31));
        Import_Y = new QToolButton(centralWidget);
        Import_Y->setObjectName(QString::fromUtf8("Import_Y"));
        Import_Y->setGeometry(QRect(820, 100, 31, 41));
        Reponses = new QPlainTextEdit(centralWidget);
        Reponses->setObjectName(QString::fromUtf8("Reponses"));
        Reponses->setGeometry(QRect(100, 100, 711, 41));
        Import_Test = new QToolButton(centralWidget);
        Import_Test->setObjectName(QString::fromUtf8("Import_Test"));
        Import_Test->setGeometry(QRect(820, 150, 31, 41));
        Fichier_test = new QPlainTextEdit(centralWidget);
        Fichier_test->setObjectName(QString::fromUtf8("Fichier_test"));
        Fichier_test->setGeometry(QRect(100, 150, 711, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 81, 41));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 150, 81, 41));
        Lancer = new QPushButton(centralWidget);
        Lancer->setObjectName(QString::fromUtf8("Lancer"));
        Lancer->setGeometry(QRect(660, 260, 71, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(158, 155, 225, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(183, 180, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(143, 139, 233, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(51, 49, 105, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(68, 65, 141, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(103, 98, 211, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(179, 176, 233, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Lancer->setPalette(palette);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 10, 201, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 340, 71, 31));
        Pred = new QPushButton(centralWidget);
        Pred->setObjectName(QString::fromUtf8("Pred"));
        Pred->setEnabled(false);
        Pred->setGeometry(QRect(200, 340, 71, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush10(QColor(157, 154, 224, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush11(QColor(206, 204, 239, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(78, 77, 112, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(105, 103, 149, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Pred->setPalette(palette1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 340, 561, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 310, 201, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_8->setFont(font1);
        Export_Params = new QCheckBox(centralWidget);
        Export_Params->setObjectName(QString::fromUtf8("Export_Params"));
        Export_Params->setGeometry(QRect(100, 220, 161, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 210, 81, 41));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        Probas_Seuil = new QCheckBox(centralWidget);
        Probas_Seuil->setObjectName(QString::fromUtf8("Probas_Seuil"));
        Probas_Seuil->setEnabled(true);
        Probas_Seuil->setGeometry(QRect(270, 220, 151, 20));
        Trier = new QCheckBox(centralWidget);
        Trier->setObjectName(QString::fromUtf8("Trier"));
        Trier->setGeometry(QRect(540, 220, 41, 20));
        Ordre = new QComboBox(centralWidget);
        Ordre->setObjectName(QString::fromUtf8("Ordre"));
        Ordre->setEnabled(false);
        Ordre->setGeometry(QRect(590, 220, 101, 27));
        QFont font3;
        font3.setPointSize(9);
        Ordre->setFont(font3);
        seuil = new QDoubleSpinBox(centralWidget);
        seuil->setObjectName(QString::fromUtf8("seuil"));
        seuil->setEnabled(false);
        seuil->setGeometry(QRect(430, 220, 91, 25));
        seuil->setDecimals(6);
        seuil->setMaximum(1);
        seuil->setSingleStep(0.01);
        seuil->setValue(0.5);
        About_Button = new QPushButton(centralWidget);
        About_Button->setObjectName(QString::fromUtf8("About_Button"));
        About_Button->setGeometry(QRect(750, 10, 101, 31));
        individu_i = new QSpinBox(centralWidget);
        individu_i->setObjectName(QString::fromUtf8("individu_i"));
        individu_i->setGeometry(QRect(90, 340, 91, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 860, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(Trier, SIGNAL(toggled(bool)), Ordre, SLOT(setEnabled(bool)));
        QObject::connect(Probas_Seuil, SIGNAL(toggled(bool)), Trier, SLOT(setDisabled(bool)));
        QObject::connect(Probas_Seuil, SIGNAL(toggled(bool)), Ordre, SLOT(setDisabled(bool)));
        QObject::connect(Probas_Seuil, SIGNAL(toggled(bool)), seuil, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projet de Credit Scoring", 0, QApplication::UnicodeUTF8));
        Import_X->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Progression", 0, QApplication::UnicodeUTF8));
        Import_Y->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        Import_Test->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Regresseurs", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Reponses", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Fichier test", 0, QApplication::UnicodeUTF8));
        Lancer->setText(QApplication::translate("MainWindow", "Lancer", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Credit Socring Software", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Individu #", 0, QApplication::UnicodeUTF8));
        Pred->setText(QApplication::translate("MainWindow", "Predire", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Proba de defaut de i = ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Predictions", 0, QApplication::UnicodeUTF8));
        Export_Params->setText(QApplication::translate("MainWindow", "Exporter parametres", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Options:", 0, QApplication::UnicodeUTF8));
        Probas_Seuil->setText(QApplication::translate("MainWindow", "Seuil de probabilite", 0, QApplication::UnicodeUTF8));
        Trier->setText(QApplication::translate("MainWindow", "Tri", 0, QApplication::UnicodeUTF8));
        About_Button->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
