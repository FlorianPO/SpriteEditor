/********************************************************************************
** Form generated from reading UI file 'SQT.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQT_H
#define UI_SQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQTClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLCDNumber *lcdNumber;
    QKeySequenceEdit *keySequenceEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SQTClass)
    {
        if (SQTClass->objectName().isEmpty())
            SQTClass->setObjectName(QStringLiteral("SQTClass"));
        SQTClass->resize(924, 833);
        centralWidget = new QWidget(SQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(830, 140, 51, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(830, 80, 51, 31));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(830, 110, 51, 31));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(540, 220, 64, 23));
        keySequenceEdit = new QKeySequenceEdit(centralWidget);
        keySequenceEdit->setObjectName(QStringLiteral("keySequenceEdit"));
        keySequenceEdit->setGeometry(QRect(450, 370, 113, 22));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(550, 90, 104, 87));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(380, 200, 104, 87));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(180, 380, 42, 22));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(150, 470, 62, 22));
        SQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 26));
        SQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SQTClass->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SQTClass->setStatusBar(statusBar);

        retranslateUi(SQTClass);

        QMetaObject::connectSlotsByName(SQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *SQTClass)
    {
        SQTClass->setWindowTitle(QApplication::translate("SQTClass", "SQT", 0));
        textBrowser_3->setHtml(QApplication::translate("SQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">dfbetnrhn</p></body></html>", 0));
        textBrowser->setHtml(QApplication::translate("SQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">dfbetnrhn</p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("SQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">dfbetnrhn</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class SQTClass: public Ui_SQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQT_H
