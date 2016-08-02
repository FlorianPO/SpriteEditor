/********************************************************************************
** Form generated from reading UI file 'InfoPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPANEL_H
#define UI_INFOPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoPanel
{
public:
    QFrame *Frame;
    QLabel *label_position;
    QLabel *label_selection;

    void setupUi(QWidget *InfoPanel)
    {
        if (InfoPanel->objectName().isEmpty())
            InfoPanel->setObjectName(QStringLiteral("InfoPanel"));
        InfoPanel->resize(129, 97);
        Frame = new QFrame(InfoPanel);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 97));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        label_position = new QLabel(Frame);
        label_position->setObjectName(QStringLiteral("label_position"));
        label_position->setGeometry(QRect(8, 4, 57, 17));
        label_position->setAutoFillBackground(false);
        label_position->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));
        label_selection = new QLabel(Frame);
        label_selection->setObjectName(QStringLiteral("label_selection"));
        label_selection->setGeometry(QRect(8, 44, 73, 17));
        label_selection->setAutoFillBackground(false);
        label_selection->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));

        retranslateUi(InfoPanel);

        QMetaObject::connectSlotsByName(InfoPanel);
    } // setupUi

    void retranslateUi(QWidget *InfoPanel)
    {
        InfoPanel->setWindowTitle(QApplication::translate("InfoPanel", "Form", 0));
        label_position->setText(QApplication::translate("InfoPanel", "Position", 0));
        label_selection->setText(QApplication::translate("InfoPanel", "S\303\251lection", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoPanel: public Ui_InfoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPANEL_H
