/********************************************************************************
** Form generated from reading UI file 'InfoPanel_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPANEL_COPY_H
#define UI_INFOPANEL_COPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoPanel_copy
{
public:
    QFrame *Frame;
    QLabel *label_copy;

    void setupUi(QWidget *InfoPanel_copy)
    {
        if (InfoPanel_copy->objectName().isEmpty())
            InfoPanel_copy->setObjectName(QStringLiteral("InfoPanel_copy"));
        InfoPanel_copy->resize(129, 57);
        Frame = new QFrame(InfoPanel_copy);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 57));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        label_copy = new QLabel(Frame);
        label_copy->setObjectName(QStringLiteral("label_copy"));
        label_copy->setGeometry(QRect(8, 4, 73, 17));
        label_copy->setAutoFillBackground(false);
        label_copy->setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
"font-weight: bold;"));

        retranslateUi(InfoPanel_copy);

        QMetaObject::connectSlotsByName(InfoPanel_copy);
    } // setupUi

    void retranslateUi(QWidget *InfoPanel_copy)
    {
        InfoPanel_copy->setWindowTitle(QApplication::translate("InfoPanel_copy", "Form", 0));
        label_copy->setText(QApplication::translate("InfoPanel_copy", "Copy", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoPanel_copy: public Ui_InfoPanel_copy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPANEL_COPY_H
