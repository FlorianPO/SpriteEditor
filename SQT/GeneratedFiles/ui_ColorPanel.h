/********************************************************************************
** Form generated from reading UI file 'ColorPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPANEL_H
#define UI_COLORPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorPanel
{
public:
    QFrame *Frame;
    QLabel *Color1;
    QLabel *Color2;

    void setupUi(QWidget *ColorPanel)
    {
        if (ColorPanel->objectName().isEmpty())
            ColorPanel->setObjectName(QStringLiteral("ColorPanel"));
        ColorPanel->resize(129, 137);
        Frame = new QFrame(ColorPanel);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 137));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        Color1 = new QLabel(Frame);
        Color1->setObjectName(QStringLiteral("Color1"));
        Color1->setGeometry(QRect(0, 0, 65, 65));
        Color1->setFrameShape(QFrame::StyledPanel);
        Color1->setFrameShadow(QFrame::Sunken);
        Color2 = new QLabel(Frame);
        Color2->setObjectName(QStringLiteral("Color2"));
        Color2->setGeometry(QRect(64, 72, 65, 65));
        Color2->setFrameShape(QFrame::StyledPanel);
        Color2->setFrameShadow(QFrame::Sunken);

        retranslateUi(ColorPanel);

        QMetaObject::connectSlotsByName(ColorPanel);
    } // setupUi

    void retranslateUi(QWidget *ColorPanel)
    {
        ColorPanel->setWindowTitle(QApplication::translate("ColorPanel", "Form", 0));
        Color1->setText(QString());
        Color2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ColorPanel: public Ui_ColorPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPANEL_H
