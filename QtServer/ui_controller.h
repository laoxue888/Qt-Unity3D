/********************************************************************************
** Form generated from reading UI file 'controller.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QFrame *frame_22;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_23;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_22;
    QDoubleSpinBox *dsB_angle_Kp;
    QFrame *frame_24;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_23;
    QDoubleSpinBox *dsB_angle_Ki;
    QFrame *frame_25;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_24;
    QDoubleSpinBox *dsB_angle_Kd;
    QLabel *label_25;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_26;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_26;
    QDoubleSpinBox *dsB_angle_vel_Kp;
    QFrame *frame_27;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_27;
    QDoubleSpinBox *dsB_angle_vel_Ki;
    QFrame *frame_28;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_28;
    QDoubleSpinBox *dsB_angle_vel_Kd;
    QPushButton *btn_angleVelPIDArgue_send_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btn_rightrotate;
    QPushButton *btn_forward;
    QPushButton *btn_up;
    QPushButton *btn_down;
    QPushButton *btn_leftrotate;
    QPushButton *btn_back;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QString::fromUtf8("Controller"));
        Controller->resize(618, 328);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Controller->sizePolicy().hasHeightForWidth());
        Controller->setSizePolicy(sizePolicy);
        Controller->setMaximumSize(QSize(618, 328));
        gridLayout_2 = new QGridLayout(Controller);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(Controller);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        frame_22 = new QFrame(Controller);
        frame_22->setObjectName(QString::fromUtf8("frame_22"));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_22);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_8 = new QGroupBox(frame_22);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_7 = new QVBoxLayout(groupBox_8);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        frame_23 = new QFrame(groupBox_8);
        frame_23->setObjectName(QString::fromUtf8("frame_23"));
        sizePolicy.setHeightForWidth(frame_23->sizePolicy().hasHeightForWidth());
        frame_23->setSizePolicy(sizePolicy);
        frame_23->setFrameShape(QFrame::StyledPanel);
        frame_23->setFrameShadow(QFrame::Raised);
        horizontalLayout_20 = new QHBoxLayout(frame_23);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(frame_23);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(26, 0));
        label_22->setTextFormat(Qt::AutoText);
        label_22->setScaledContents(true);
        label_22->setAlignment(Qt::AlignCenter);
        label_22->setWordWrap(false);

        horizontalLayout_20->addWidget(label_22);

        dsB_angle_Kp = new QDoubleSpinBox(frame_23);
        dsB_angle_Kp->setObjectName(QString::fromUtf8("dsB_angle_Kp"));
        dsB_angle_Kp->setDecimals(4);
        dsB_angle_Kp->setMinimum(-100000.000000000000000);
        dsB_angle_Kp->setMaximum(100000.000000000000000);
        dsB_angle_Kp->setSingleStep(0.010000000000000);

        horizontalLayout_20->addWidget(dsB_angle_Kp);


        verticalLayout_7->addWidget(frame_23);

        frame_24 = new QFrame(groupBox_8);
        frame_24->setObjectName(QString::fromUtf8("frame_24"));
        frame_24->setFrameShape(QFrame::StyledPanel);
        frame_24->setFrameShadow(QFrame::Raised);
        horizontalLayout_21 = new QHBoxLayout(frame_24);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(frame_24);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(26, 0));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_23);

        dsB_angle_Ki = new QDoubleSpinBox(frame_24);
        dsB_angle_Ki->setObjectName(QString::fromUtf8("dsB_angle_Ki"));
        dsB_angle_Ki->setDecimals(4);
        dsB_angle_Ki->setMinimum(-100000.000000000000000);
        dsB_angle_Ki->setMaximum(100000.000000000000000);
        dsB_angle_Ki->setSingleStep(0.010000000000000);

        horizontalLayout_21->addWidget(dsB_angle_Ki);


        verticalLayout_7->addWidget(frame_24);

        frame_25 = new QFrame(groupBox_8);
        frame_25->setObjectName(QString::fromUtf8("frame_25"));
        frame_25->setFrameShape(QFrame::StyledPanel);
        frame_25->setFrameShadow(QFrame::Raised);
        horizontalLayout_22 = new QHBoxLayout(frame_25);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(frame_25);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(26, 0));
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_24);

        dsB_angle_Kd = new QDoubleSpinBox(frame_25);
        dsB_angle_Kd->setObjectName(QString::fromUtf8("dsB_angle_Kd"));
        dsB_angle_Kd->setDecimals(4);
        dsB_angle_Kd->setMinimum(-100000.000000000000000);
        dsB_angle_Kd->setMaximum(100000.000000000000000);
        dsB_angle_Kd->setSingleStep(0.010000000000000);

        horizontalLayout_22->addWidget(dsB_angle_Kd);


        verticalLayout_7->addWidget(frame_25);


        gridLayout_5->addWidget(groupBox_8, 1, 0, 1, 1);

        label_25 = new QLabel(frame_22);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMaximumSize(QSize(16777215, 20));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_25, 0, 0, 1, 2);

        groupBox_9 = new QGroupBox(frame_22);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_8 = new QVBoxLayout(groupBox_9);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_26 = new QFrame(groupBox_9);
        frame_26->setObjectName(QString::fromUtf8("frame_26"));
        frame_26->setFrameShape(QFrame::StyledPanel);
        frame_26->setFrameShadow(QFrame::Raised);
        horizontalLayout_23 = new QHBoxLayout(frame_26);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(frame_26);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(26, 0));
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_23->addWidget(label_26);

        dsB_angle_vel_Kp = new QDoubleSpinBox(frame_26);
        dsB_angle_vel_Kp->setObjectName(QString::fromUtf8("dsB_angle_vel_Kp"));
        dsB_angle_vel_Kp->setDecimals(4);
        dsB_angle_vel_Kp->setMinimum(-100000.000000000000000);
        dsB_angle_vel_Kp->setMaximum(100000.000000000000000);
        dsB_angle_vel_Kp->setSingleStep(0.010000000000000);

        horizontalLayout_23->addWidget(dsB_angle_vel_Kp);


        verticalLayout_8->addWidget(frame_26);

        frame_27 = new QFrame(groupBox_9);
        frame_27->setObjectName(QString::fromUtf8("frame_27"));
        frame_27->setFrameShape(QFrame::StyledPanel);
        frame_27->setFrameShadow(QFrame::Raised);
        horizontalLayout_24 = new QHBoxLayout(frame_27);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(frame_27);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(26, 0));
        label_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_24->addWidget(label_27);

        dsB_angle_vel_Ki = new QDoubleSpinBox(frame_27);
        dsB_angle_vel_Ki->setObjectName(QString::fromUtf8("dsB_angle_vel_Ki"));
        dsB_angle_vel_Ki->setDecimals(4);
        dsB_angle_vel_Ki->setMinimum(-100000.000000000000000);
        dsB_angle_vel_Ki->setMaximum(100000.000000000000000);
        dsB_angle_vel_Ki->setSingleStep(0.010000000000000);

        horizontalLayout_24->addWidget(dsB_angle_vel_Ki);


        verticalLayout_8->addWidget(frame_27);

        frame_28 = new QFrame(groupBox_9);
        frame_28->setObjectName(QString::fromUtf8("frame_28"));
        frame_28->setFrameShape(QFrame::StyledPanel);
        frame_28->setFrameShadow(QFrame::Raised);
        horizontalLayout_25 = new QHBoxLayout(frame_28);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(frame_28);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(26, 0));
        label_28->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(label_28);

        dsB_angle_vel_Kd = new QDoubleSpinBox(frame_28);
        dsB_angle_vel_Kd->setObjectName(QString::fromUtf8("dsB_angle_vel_Kd"));
        dsB_angle_vel_Kd->setDecimals(4);
        dsB_angle_vel_Kd->setMinimum(-100000.000000000000000);
        dsB_angle_vel_Kd->setMaximum(100000.000000000000000);
        dsB_angle_vel_Kd->setSingleStep(0.010000000000000);

        horizontalLayout_25->addWidget(dsB_angle_vel_Kd);


        verticalLayout_8->addWidget(frame_28);


        gridLayout_5->addWidget(groupBox_9, 1, 1, 1, 1);

        btn_angleVelPIDArgue_send_4 = new QPushButton(frame_22);
        btn_angleVelPIDArgue_send_4->setObjectName(QString::fromUtf8("btn_angleVelPIDArgue_send_4"));

        gridLayout_5->addWidget(btn_angleVelPIDArgue_send_4, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_22, 1, 0, 1, 1);

        groupBox = new QGroupBox(Controller);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(168, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_rightrotate = new QPushButton(groupBox);
        btn_rightrotate->setObjectName(QString::fromUtf8("btn_rightrotate"));

        gridLayout->addWidget(btn_rightrotate, 5, 2, 1, 1);

        btn_forward = new QPushButton(groupBox);
        btn_forward->setObjectName(QString::fromUtf8("btn_forward"));

        gridLayout->addWidget(btn_forward, 3, 1, 1, 1);

        btn_up = new QPushButton(groupBox);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));

        gridLayout->addWidget(btn_up, 0, 1, 1, 1);

        btn_down = new QPushButton(groupBox);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));

        gridLayout->addWidget(btn_down, 1, 1, 1, 1);

        btn_leftrotate = new QPushButton(groupBox);
        btn_leftrotate->setObjectName(QString::fromUtf8("btn_leftrotate"));

        gridLayout->addWidget(btn_leftrotate, 5, 0, 1, 1);

        btn_back = new QPushButton(groupBox);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));

        gridLayout->addWidget(btn_back, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 3);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);


        retranslateUi(Controller);

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QWidget *Controller)
    {
        Controller->setWindowTitle(QCoreApplication::translate("Controller", "Controller", nullptr));
        pushButton->setText(QCoreApplication::translate("Controller", "\350\257\273\345\217\226", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("Controller", "\345\215\207\351\231\215\351\200\237\345\272\246PID", nullptr));
        label_22->setText(QCoreApplication::translate("Controller", "Kp", nullptr));
        label_23->setText(QCoreApplication::translate("Controller", "Ki", nullptr));
        label_24->setText(QCoreApplication::translate("Controller", "Kd", nullptr));
        label_25->setText(QCoreApplication::translate("Controller", "\345\215\207\351\231\215\350\277\220\345\212\250", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("Controller", "\351\253\230\345\272\246PID", nullptr));
        label_26->setText(QCoreApplication::translate("Controller", "Kp", nullptr));
        label_27->setText(QCoreApplication::translate("Controller", "Ki", nullptr));
        label_28->setText(QCoreApplication::translate("Controller", "Kd", nullptr));
        btn_angleVelPIDArgue_send_4->setText(QCoreApplication::translate("Controller", "\345\217\221\351\200\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Controller", "\346\216\247\345\210\266", nullptr));
        btn_rightrotate->setText(QCoreApplication::translate("Controller", "\345\217\263", nullptr));
        btn_forward->setText(QCoreApplication::translate("Controller", "\345\211\215", nullptr));
        btn_up->setText(QCoreApplication::translate("Controller", "\344\270\212\345\215\207", nullptr));
        btn_down->setText(QCoreApplication::translate("Controller", "\351\231\215\350\220\275", nullptr));
        btn_leftrotate->setText(QCoreApplication::translate("Controller", "\345\267\246", nullptr));
        btn_back->setText(QCoreApplication::translate("Controller", "\345\220\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
