/********************************************************************************
** Form generated from reading UI file 'BrushPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRUSHPANEL_H
#define UI_BRUSHPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrushPanel
{
public:
    QFrame *Frame;
    QLabel *label_opacity;
    QLabel *label_seuil;
    QTabWidget *Brushes;
    QWidget *Default;
    QFrame *DefaultFrame;
    QWidget *Custom;

    void setupUi(QWidget *BrushPanel)
    {
        if (BrushPanel->objectName().isEmpty())
            BrushPanel->setObjectName(QStringLiteral("BrushPanel"));
        BrushPanel->resize(129, 161);
        Frame = new QFrame(BrushPanel);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 161));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        label_opacity = new QLabel(Frame);
        label_opacity->setObjectName(QStringLiteral("label_opacity"));
        label_opacity->setGeometry(QRect(64, 0, 57, 17));
        label_opacity->setAutoFillBackground(false);
        label_opacity->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));
        label_seuil = new QLabel(Frame);
        label_seuil->setObjectName(QStringLiteral("label_seuil"));
        label_seuil->setGeometry(QRect(64, 16, 57, 16));
        label_seuil->setAutoFillBackground(false);
        label_seuil->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));
        Brushes = new QTabWidget(Frame);
        Brushes->setObjectName(QStringLiteral("Brushes"));
        Brushes->setGeometry(QRect(0, 56, 129, 102));
        Brushes->setMouseTracking(true);
        Brushes->setFocusPolicy(Qt::NoFocus);
        Brushes->setContextMenuPolicy(Qt::NoContextMenu);
        Brushes->setAcceptDrops(false);
        Brushes->setTabPosition(QTabWidget::South);
        Brushes->setTabShape(QTabWidget::Rounded);
        Brushes->setElideMode(Qt::ElideRight);
        Brushes->setUsesScrollButtons(false);
        Brushes->setDocumentMode(false);
        Brushes->setMovable(true);
        Brushes->setTabBarAutoHide(false);
        Default = new QWidget();
        Default->setObjectName(QStringLiteral("Default"));
        Default->setContextMenuPolicy(Qt::DefaultContextMenu);
        DefaultFrame = new QFrame(Default);
        DefaultFrame->setObjectName(QStringLiteral("DefaultFrame"));
        DefaultFrame->setGeometry(QRect(0, 0, 129, 74));
        DefaultFrame->setFrameShape(QFrame::StyledPanel);
        DefaultFrame->setFrameShadow(QFrame::Raised);
        Brushes->addTab(Default, QString());
        Custom = new QWidget();
        Custom->setObjectName(QStringLiteral("Custom"));
        Brushes->addTab(Custom, QString());
        Brushes->raise();
        label_opacity->raise();
        label_seuil->raise();

        retranslateUi(BrushPanel);

        Brushes->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BrushPanel);
    } // setupUi

    void retranslateUi(QWidget *BrushPanel)
    {
        BrushPanel->setWindowTitle(QApplication::translate("BrushPanel", "Form", 0));
        label_opacity->setText(QApplication::translate("BrushPanel", "Opacit\303\251", 0));
        label_seuil->setText(QApplication::translate("BrushPanel", "Seuil", 0));
        Brushes->setTabText(Brushes->indexOf(Default), QApplication::translate("BrushPanel", "Default", 0));
        Brushes->setTabText(Brushes->indexOf(Custom), QApplication::translate("BrushPanel", "Custom", 0));
    } // retranslateUi

};

namespace Ui {
    class BrushPanel: public Ui_BrushPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRUSHPANEL_H
