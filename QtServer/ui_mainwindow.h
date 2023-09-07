/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_data_send;
    QPushButton *btn_sendText_clear;
    QLabel *label;
    QPushButton *btn_sendText;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *tB_status;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_clear;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cB_mainwinBringToFront;
    QSplitter *splitter;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *vL_chk_view;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *vL_data_view;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 483);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter_3 = new QSplitter(tab);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        frame_4 = new QFrame(splitter_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_data_send = new QTextEdit(frame_4);
        textEdit_data_send->setObjectName(QString::fromUtf8("textEdit_data_send"));

        gridLayout_2->addWidget(textEdit_data_send, 1, 0, 1, 2);

        btn_sendText_clear = new QPushButton(frame_4);
        btn_sendText_clear->setObjectName(QString::fromUtf8("btn_sendText_clear"));

        gridLayout_2->addWidget(btn_sendText_clear, 2, 0, 1, 1);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        btn_sendText = new QPushButton(frame_4);
        btn_sendText->setObjectName(QString::fromUtf8("btn_sendText"));

        gridLayout_2->addWidget(btn_sendText, 2, 1, 1, 1);

        splitter_3->addWidget(frame_4);
        frame_5 = new QFrame(splitter_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        tB_status = new QTextBrowser(frame_5);
        tB_status->setObjectName(QString::fromUtf8("tB_status"));

        verticalLayout->addWidget(tB_status);

        splitter_3->addWidget(frame_5);

        verticalLayout_3->addWidget(splitter_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        splitter_2 = new QSplitter(tab_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 20));
        frame->setMaximumSize(QSize(16777215, 45));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_clear = new QPushButton(frame);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout->addWidget(btn_clear);

        horizontalSpacer = new QSpacerItem(317, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cB_mainwinBringToFront = new QCheckBox(frame);
        cB_mainwinBringToFront->setObjectName(QString::fromUtf8("cB_mainwinBringToFront"));
        cB_mainwinBringToFront->setChecked(true);

        horizontalLayout->addWidget(cB_mainwinBringToFront);

        splitter_2->addWidget(frame);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(113, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 109, 300));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        vL_chk_view = new QVBoxLayout();
        vL_chk_view->setObjectName(QString::fromUtf8("vL_chk_view"));

        verticalLayout_4->addLayout(vL_chk_view);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        splitter->addWidget(frame_2);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        vL_data_view = new QVBoxLayout();
        vL_data_view->setObjectName(QString::fromUtf8("vL_data_view"));

        verticalLayout_6->addLayout(vL_data_view);

        splitter->addWidget(frame_3);
        splitter_2->addWidget(splitter);

        verticalLayout_7->addWidget(splitter_2);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 860, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt&Unity3D\350\201\224\345\220\210\350\260\203\350\257\225", nullptr));
        btn_sendText_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(statustip)
        btn_sendText->setStatusTip(QCoreApplication::translate("MainWindow", "\344\273\245\345\255\227\347\254\246\344\270\262\347\232\204\345\275\242\345\274\217\345\217\221\351\200\201", nullptr));
#endif // QT_CONFIG(statustip)
        btn_sendText->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Raw Data", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        cB_mainwinBringToFront->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\345\211\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Data Curve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
