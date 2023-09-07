#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uchart.h"
#include <QLineSeries>
#include "tcpworker.h"

class QTcpServer;
class QTcpSocket;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private:
    QTcpServer *tcpServer; //服务器
    TcpWorker *tcpWorker;

    //数据显示
    UChart *view_PID_Data;

    //定义子线程，用于接收Tcp数据
    QThread getTcpDataThread;

    //曲线序列
    QHash<QString, QLineSeries *> data_series;

private slots:
    void showTcpWorkerMessage(QString statusText);

    void on_btn_sendText_clicked();
    void on_btn_sendText_clear_clicked();

    void getParseData(QHash<QString, double> parseData);

    void chk_connect_series();
    void on_btn_clear_clicked();
    void on_cB_mainwinBringToFront_clicked(bool checked);

};
#endif // MAINWINDOW_H
