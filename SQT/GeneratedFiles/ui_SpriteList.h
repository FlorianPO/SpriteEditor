/********************************************************************************
** Form generated from reading UI file 'SpriteList.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITELIST_H
#define UI_SPRITELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteList
{
public:
    QFrame *frame;
    QCheckBox *check_box;

    void setupUi(QWidget *SpriteList)
    {
        if (SpriteList->objectName().isEmpty())
            SpriteList->setObjectName(QStringLiteral("SpriteList"));
        SpriteList->resize(217, 33);
        frame = new QFrame(SpriteList);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 211, 33));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        check_box = new QCheckBox(frame);
        check_box->setObjectName(QStringLiteral("check_box"));
        check_box->setGeometry(QRect(8, 0, 17, 33));

        retranslateUi(SpriteList);

        QMetaObject::connectSlotsByName(SpriteList);
    } // setupUi

    void retranslateUi(QWidget *SpriteList)
    {
        SpriteList->setWindowTitle(QApplication::translate("SpriteList", "Form", 0));
        check_box->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpriteList: public Ui_SpriteList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITELIST_H
