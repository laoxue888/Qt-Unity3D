#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qRegisterMetaType<QHash<QString, double>>("QHash<QString, double>");//发出信号方要注册
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);//窗口总是显示在最前
    w.show();
    return a.exec();
}
