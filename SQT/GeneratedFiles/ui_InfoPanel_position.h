/********************************************************************************
** Form generated from reading UI file 'InfoPanel_position.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPANEL_POSITION_H
#define UI_INFOPANEL_POSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoPanel_position
{
public:
    QFrame *Frame;
    QLabel *label_position;

    void setupUi(QWidget *InfoPanel_position)
    {
        if (InfoPanel_position->objectName().isEmpty())
            InfoPanel_position->setObjectName(QStringLiteral("InfoPanel_position"));
        InfoPanel_position->resize(129, 41);
        Frame = new QFrame(InfoPanel_position);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 41));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        label_position = new QLabel(Frame);
        label_position->setObjectName(QStringLiteral("label_position"));
        label_position->setGeometry(QRect(8, 4, 57, 17));
        label_position->setAutoFillBackground(false);
        label_position->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));

        retranslateUi(InfoPanel_position);

        QMetaObject::connectSlotsByName(InfoPanel_position);
    } // setupUi

    void retranslateUi(QWidget *InfoPanel_position)
    {
        InfoPanel_position->setWindowTitle(QApplication::translate("InfoPanel_position", "Form", 0));
        label_position->setText(QApplication::translate("InfoPanel_position", "Position", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoPanel_position: public Ui_InfoPanel_position {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPANEL_POSITION_H
