/********************************************************************************
** Form generated from reading UI file 'InfoPanel_selection.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPANEL_SELECTION_H
#define UI_INFOPANEL_SELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoPanel_selection
{
public:
    QFrame *Frame;
    QLabel *label_position;

    void setupUi(QWidget *InfoPanel_selection)
    {
        if (InfoPanel_selection->objectName().isEmpty())
            InfoPanel_selection->setObjectName(QStringLiteral("InfoPanel_selection"));
        InfoPanel_selection->resize(129, 57);
        Frame = new QFrame(InfoPanel_selection);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 57));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        label_position = new QLabel(Frame);
        label_position->setObjectName(QStringLiteral("label_position"));
        label_position->setGeometry(QRect(8, 4, 73, 17));
        label_position->setAutoFillBackground(false);
        label_position->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));

        retranslateUi(InfoPanel_selection);

        QMetaObject::connectSlotsByName(InfoPanel_selection);
    } // setupUi

    void retranslateUi(QWidget *InfoPanel_selection)
    {
        InfoPanel_selection->setWindowTitle(QApplication::translate("InfoPanel_selection", "Form", 0));
        label_position->setText(QApplication::translate("InfoPanel_selection", "S\303\251lection", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoPanel_selection: public Ui_InfoPanel_selection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPANEL_SELECTION_H
