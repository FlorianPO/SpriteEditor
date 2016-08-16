/********************************************************************************
** Form generated from reading UI file 'ToolPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPANEL_H
#define UI_TOOLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolPanel
{
public:
    QFrame *Frame;
    QPushButton *Tool_crayon;
    QPushButton *Tool_gomme;
    QPushButton *Tool_rect_select;
    QPushButton *Tool_aero;
    QPushButton *Tool_pot;
    QPushButton *Tool_none1;
    QPushButton *Tool_baguette;
    QPushButton *Tool_selec_color;
    QPushButton *Tool_snap;
    QPushButton *Tool_none2;
    QPushButton *Tool_move;
    QPushButton *Tool_grand;
    QPushButton *Tool_rotation;
    QPushButton *Tool_flip;
    QPushButton *Tool_none3;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *ToolPanel)
    {
        if (ToolPanel->objectName().isEmpty())
            ToolPanel->setObjectName(QStringLiteral("ToolPanel"));
        ToolPanel->resize(129, 81);
        Frame = new QFrame(ToolPanel);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 81));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        Tool_crayon = new QPushButton(Frame);
        buttonGroup = new QButtonGroup(ToolPanel);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(Tool_crayon);
        Tool_crayon->setObjectName(QStringLiteral("Tool_crayon"));
        Tool_crayon->setGeometry(QRect(4, 4, 25, 25));
        Tool_crayon->setFocusPolicy(Qt::NoFocus);
        Tool_crayon->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Tools/tool_crayon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_crayon->setIcon(icon);
        Tool_crayon->setIconSize(QSize(23, 23));
        Tool_crayon->setCheckable(true);
        Tool_crayon->setAutoDefault(false);
        Tool_crayon->setFlat(true);
        Tool_gomme = new QPushButton(Frame);
        buttonGroup->addButton(Tool_gomme);
        Tool_gomme->setObjectName(QStringLiteral("Tool_gomme"));
        Tool_gomme->setGeometry(QRect(28, 4, 25, 25));
        Tool_gomme->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Tools/tool_gomme.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_gomme->setIcon(icon1);
        Tool_gomme->setIconSize(QSize(23, 23));
        Tool_gomme->setCheckable(true);
        Tool_gomme->setAutoDefault(false);
        Tool_gomme->setFlat(true);
        Tool_rect_select = new QPushButton(Frame);
        buttonGroup->addButton(Tool_rect_select);
        Tool_rect_select->setObjectName(QStringLiteral("Tool_rect_select"));
        Tool_rect_select->setGeometry(QRect(3, 28, 25, 25));
        Tool_rect_select->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Tools/tool_rectselect.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_rect_select->setIcon(icon2);
        Tool_rect_select->setIconSize(QSize(23, 23));
        Tool_rect_select->setCheckable(true);
        Tool_rect_select->setAutoDefault(false);
        Tool_rect_select->setFlat(true);
        Tool_aero = new QPushButton(Frame);
        buttonGroup->addButton(Tool_aero);
        Tool_aero->setObjectName(QStringLiteral("Tool_aero"));
        Tool_aero->setGeometry(QRect(52, 4, 25, 25));
        Tool_aero->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/Tools/tool_aero.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_aero->setIcon(icon3);
        Tool_aero->setIconSize(QSize(23, 23));
        Tool_aero->setCheckable(true);
        Tool_aero->setAutoDefault(false);
        Tool_aero->setFlat(true);
        Tool_pot = new QPushButton(Frame);
        buttonGroup->addButton(Tool_pot);
        Tool_pot->setObjectName(QStringLiteral("Tool_pot"));
        Tool_pot->setGeometry(QRect(76, 4, 25, 25));
        Tool_pot->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QStringLiteral("Resources/Tools/tool_pot.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_pot->setIcon(icon4);
        Tool_pot->setIconSize(QSize(23, 23));
        Tool_pot->setCheckable(true);
        Tool_pot->setAutoDefault(false);
        Tool_pot->setFlat(true);
        Tool_none1 = new QPushButton(Frame);
        buttonGroup->addButton(Tool_none1);
        Tool_none1->setObjectName(QStringLiteral("Tool_none1"));
        Tool_none1->setGeometry(QRect(100, 4, 25, 25));
        Tool_none1->setFocusPolicy(Qt::NoFocus);
        Tool_none1->setIconSize(QSize(23, 23));
        Tool_none1->setCheckable(true);
        Tool_none1->setAutoDefault(false);
        Tool_none1->setFlat(true);
        Tool_baguette = new QPushButton(Frame);
        buttonGroup->addButton(Tool_baguette);
        Tool_baguette->setObjectName(QStringLiteral("Tool_baguette"));
        Tool_baguette->setGeometry(QRect(28, 28, 25, 25));
        Tool_baguette->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QStringLiteral("Resources/Tools/tool_baguette.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_baguette->setIcon(icon5);
        Tool_baguette->setIconSize(QSize(23, 23));
        Tool_baguette->setCheckable(true);
        Tool_baguette->setAutoDefault(false);
        Tool_baguette->setFlat(true);
        Tool_selec_color = new QPushButton(Frame);
        buttonGroup->addButton(Tool_selec_color);
        Tool_selec_color->setObjectName(QStringLiteral("Tool_selec_color"));
        Tool_selec_color->setGeometry(QRect(52, 28, 25, 25));
        Tool_selec_color->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QStringLiteral("Resources/Tools/tool_seleccolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_selec_color->setIcon(icon6);
        Tool_selec_color->setIconSize(QSize(23, 23));
        Tool_selec_color->setCheckable(true);
        Tool_selec_color->setAutoDefault(false);
        Tool_selec_color->setFlat(true);
        Tool_snap = new QPushButton(Frame);
        buttonGroup->addButton(Tool_snap);
        Tool_snap->setObjectName(QStringLiteral("Tool_snap"));
        Tool_snap->setGeometry(QRect(76, 28, 25, 25));
        Tool_snap->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QStringLiteral("Resources/Tools/tool_snap.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_snap->setIcon(icon7);
        Tool_snap->setIconSize(QSize(23, 23));
        Tool_snap->setCheckable(true);
        Tool_snap->setAutoDefault(false);
        Tool_snap->setFlat(true);
        Tool_none2 = new QPushButton(Frame);
        buttonGroup->addButton(Tool_none2);
        Tool_none2->setObjectName(QStringLiteral("Tool_none2"));
        Tool_none2->setGeometry(QRect(100, 28, 25, 25));
        Tool_none2->setFocusPolicy(Qt::NoFocus);
        Tool_none2->setIconSize(QSize(23, 23));
        Tool_none2->setCheckable(true);
        Tool_none2->setAutoDefault(false);
        Tool_none2->setFlat(true);
        Tool_move = new QPushButton(Frame);
        buttonGroup->addButton(Tool_move);
        Tool_move->setObjectName(QStringLiteral("Tool_move"));
        Tool_move->setGeometry(QRect(4, 52, 25, 25));
        Tool_move->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QStringLiteral("Resources/Tools/tool_move.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_move->setIcon(icon8);
        Tool_move->setIconSize(QSize(23, 23));
        Tool_move->setCheckable(true);
        Tool_move->setAutoDefault(false);
        Tool_move->setFlat(true);
        Tool_grand = new QPushButton(Frame);
        buttonGroup->addButton(Tool_grand);
        Tool_grand->setObjectName(QStringLiteral("Tool_grand"));
        Tool_grand->setGeometry(QRect(28, 52, 25, 25));
        Tool_grand->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QStringLiteral("Resources/Tools/tool_grand.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_grand->setIcon(icon9);
        Tool_grand->setIconSize(QSize(23, 23));
        Tool_grand->setCheckable(true);
        Tool_grand->setAutoDefault(false);
        Tool_grand->setFlat(true);
        Tool_rotation = new QPushButton(Frame);
        buttonGroup->addButton(Tool_rotation);
        Tool_rotation->setObjectName(QStringLiteral("Tool_rotation"));
        Tool_rotation->setGeometry(QRect(52, 52, 25, 25));
        Tool_rotation->setFocusPolicy(Qt::NoFocus);
        QIcon icon10;
        icon10.addFile(QStringLiteral("Resources/Tools/tool_rotation.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_rotation->setIcon(icon10);
        Tool_rotation->setIconSize(QSize(23, 23));
        Tool_rotation->setCheckable(true);
        Tool_rotation->setAutoDefault(false);
        Tool_rotation->setFlat(true);
        Tool_flip = new QPushButton(Frame);
        buttonGroup->addButton(Tool_flip);
        Tool_flip->setObjectName(QStringLiteral("Tool_flip"));
        Tool_flip->setGeometry(QRect(76, 52, 25, 25));
        Tool_flip->setFocusPolicy(Qt::NoFocus);
        QIcon icon11;
        icon11.addFile(QStringLiteral("Resources/Tools/tool_flip.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tool_flip->setIcon(icon11);
        Tool_flip->setIconSize(QSize(23, 23));
        Tool_flip->setCheckable(true);
        Tool_flip->setAutoDefault(false);
        Tool_flip->setFlat(true);
        Tool_none3 = new QPushButton(Frame);
        buttonGroup->addButton(Tool_none3);
        Tool_none3->setObjectName(QStringLiteral("Tool_none3"));
        Tool_none3->setGeometry(QRect(100, 52, 25, 25));
        Tool_none3->setFocusPolicy(Qt::NoFocus);
        Tool_none3->setIconSize(QSize(23, 23));
        Tool_none3->setCheckable(true);
        Tool_none3->setAutoDefault(false);
        Tool_none3->setFlat(true);

        retranslateUi(ToolPanel);

        Tool_crayon->setDefault(false);
        Tool_gomme->setDefault(false);
        Tool_rect_select->setDefault(false);
        Tool_aero->setDefault(false);
        Tool_pot->setDefault(false);
        Tool_none1->setDefault(false);
        Tool_baguette->setDefault(false);
        Tool_selec_color->setDefault(false);
        Tool_snap->setDefault(false);
        Tool_none2->setDefault(false);
        Tool_move->setDefault(false);
        Tool_grand->setDefault(false);
        Tool_rotation->setDefault(false);
        Tool_flip->setDefault(false);
        Tool_none3->setDefault(false);


        QMetaObject::connectSlotsByName(ToolPanel);
    } // setupUi

    void retranslateUi(QWidget *ToolPanel)
    {
        ToolPanel->setWindowTitle(QApplication::translate("ToolPanel", "Form", 0));
        Tool_gomme->setText(QString());
        Tool_rect_select->setText(QString());
        Tool_aero->setText(QString());
        Tool_pot->setText(QString());
        Tool_none1->setText(QApplication::translate("ToolPanel", "E", 0));
        Tool_baguette->setText(QString());
        Tool_selec_color->setText(QString());
        Tool_snap->setText(QString());
        Tool_none2->setText(QApplication::translate("ToolPanel", "E", 0));
        Tool_move->setText(QString());
        Tool_grand->setText(QString());
        Tool_rotation->setText(QString());
        Tool_flip->setText(QString());
        Tool_none3->setText(QApplication::translate("ToolPanel", "E", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolPanel: public Ui_ToolPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPANEL_H
