/********************************************************************************
** Form generated from reading UI file 'LayerList.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERLIST_H
#define UI_LAYERLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LayerList
{
public:
    QFrame *Frame;

    void setupUi(QWidget *LayerList)
    {
        if (LayerList->objectName().isEmpty())
            LayerList->setObjectName(QStringLiteral("LayerList"));
        LayerList->resize(129, 33);
        Frame = new QFrame(LayerList);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 33));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);

        retranslateUi(LayerList);

        QMetaObject::connectSlotsByName(LayerList);
    } // setupUi

    void retranslateUi(QWidget *LayerList)
    {
        LayerList->setWindowTitle(QApplication::translate("LayerList", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class LayerList: public Ui_LayerList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERLIST_H
