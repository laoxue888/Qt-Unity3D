#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include "QChart"
#include "QCheckBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //关闭主窗口后，子窗口也关闭
    this->setAttribute(Qt::WA_DeleteOnClose);

    //Tcp子线程，
    //初始化server并监听
    tcpServer = new QTcpServer(this); //qt自己内存管理
    tcpWorker = new TcpWorker(tcpServer);
//    getTcpDataThread = new QThread(this);

//    if(!tcpServer->listen(QHostAddress::Any,6666)) //监听所有网络地址，端口6666
//        qDebug()<<tcpServer->errorString();
//    connect(tcpServer,&QTcpServer::newConnection,tcpWorker,&TcpWorker::SocketConnect);

    tcpWorker->moveToThread(&getTcpDataThread);//将这个对象移入子线程
    getTcpDataThread.start();

    //获取子线程的状态信息
    connect(tcpWorker, &TcpWorker::TcpStatusMessage, this ,&MainWindow::showTcpWorkerMessage);
    connect(tcpWorker,&TcpWorker::sendDataToGUI, this, &MainWindow::getParseData);
    ui->tB_status->document()->setMaximumBlockCount(1000);//设置记录的最大行数
    QString statusText;
    statusText.append("等待连接...\n");
    ui->tB_status->append(statusText);

    //xy图初始化
    view_PID_Data = new UChart(this);
    ui->vL_data_view->addWidget(view_PID_Data);

}

MainWindow::~MainWindow()
{
    getTcpDataThread.quit();
    getTcpDataThread.wait();

    delete ui;
}

void MainWindow::showTcpWorkerMessage(QString statusText)
{
    ui->tB_status->append(statusText);
}

void MainWindow::on_btn_sendText_clicked()
{
    QString dataSendStr = ui->textEdit_data_send->toPlainText();//获取要发送的数据
    qDebug()<<"要发送的数据："<<dataSendStr;
//    SocketSend(dataSendStr);
    if(tcpWorker->isConnected)
    {
        tcpWorker->SocketSend(dataSendStr);
        ui->statusbar->showMessage("已发送数据",3000);
    }
}

void MainWindow::on_btn_sendText_clear_clicked()
{
    ui->textEdit_data_send->clear();
}

void MainWindow::getParseData(QHash<QString, double> parseData)
{
    qDebug()<<"GUI接收到的解析数据：" << parseData;

    QHashIterator<QString,double>i_dis(parseData);
    while(i_dis.hasNext())
    {
        i_dis.next();
        ui->tB_status->append(i_dis.key()+QString::number(i_dis.value()));
    }

    //序列初始化
    static int interval_init_count = 0;
    static bool isFinishInit = false;
    if(parseData.size() != data_series.size())
    {
        isFinishInit = false;
    }
    interval_init_count++;
    if(interval_init_count == 20)
    {
        QHashIterator<QString, double>i(parseData);
        while(i.hasNext())
        {
            i.next();
            //如果不存的话，就初始化一下
            if(!data_series.contains(i.key()))
            {
                //初始化二维图
                QLineSeries *lineseries_2D_temp = new QLineSeries;
                lineseries_2D_temp->setName(i.key());

//                    lineseries_2D_temp->setMarkerSize(5.0);
//                    lineseries_2D_temp->setPointsVisible(true);

                view_PID_Data->m_chart->addSeries(lineseries_2D_temp);
                lineseries_2D_temp->attachAxis(view_PID_Data->axisX_Time);
                lineseries_2D_temp->attachAxis(view_PID_Data->axisY);

                QCheckBox *chkbutton = new QCheckBox(i.key(), this);
                chkbutton->setCheckState(Qt::Checked);
                //连接信号与槽
                connect(chkbutton, &QPushButton::clicked, this, &MainWindow::chk_connect_series);
                ui->vL_chk_view->addWidget(chkbutton);//将控件添加到布局中
                //设置QCheckBox颜色
                QColor seriesColor = lineseries_2D_temp->color();//获取序列的颜色
                QRgb color_rgb = seriesColor.rgb();
                QString colorSet_string = "QCheckBox{color:rgb("+ QString::number(qRed(color_rgb))+ "," + QString::number(qGreen(color_rgb)) \
                        + ","+ QString::number(qBlue(color_rgb)) + ");}";//颜色设置
                chkbutton->setStyleSheet(colorSet_string);

//                connect(lineseries_2D_temp, &QLineSeries::clicked, view_PID_Data, &UChart::keepCallout);
                connect(lineseries_2D_temp, &QLineSeries::hovered, view_PID_Data, &UChart::tooltip);

                data_series.insert(i.key(), lineseries_2D_temp);
            }
        }
        isFinishInit = true;

        //重置
        interval_init_count = 0;
    }

    //序列更新
    if(isFinishInit)
    {
        //每增加一个点改变X轴的范围，实现曲线的动态更新效果
        QDateTime bjtime = QDateTime::currentDateTime();
        view_PID_Data->axisX_Time->setMin(QDateTime::currentDateTime().addSecs(-60*0.2));
        view_PID_Data->axisX_Time->setMax(QDateTime::currentDateTime().addSecs(0));

        QHashIterator<QString, double>i(parseData);
        while(i.hasNext())
        {
            i.next();
            data_series[i.key()]->append(bjtime.toMSecsSinceEpoch(), i.value());

            if(data_series[i.key()]->count() > 1000)
            {
                data_series[i.key()]->remove(0);
            }

        }

    }
}

void MainWindow::chk_connect_series()
{
    //QCheckBox事件
    QCheckBox *button = (QCheckBox *)(sender());//关键是这一步，获取发送信号的对象
    QHashIterator<QString, QLineSeries*>i(data_series);
    while(i.hasNext())
    {
        i.next();
        if((button->text()==i.value()->name()) && (button->isChecked()))
        {
            data_series[i.key()]->setVisible(true);
        }

        if((button->text()==i.value()->name()) && (!button->isChecked()))
        {
            data_series[i.key()]->setVisible(false);
        }

    }
}

void MainWindow::on_btn_clear_clicked()
{
    //清空
    // 删除2D布局中所有的控件
    while(ui->vL_chk_view->count())
    {
         QWidget *p=this->ui->vL_chk_view->itemAt(0)->widget();
         p->setParent (NULL);
         this->ui->vL_chk_view->removeWidget(p);
         delete p; // 清除内存
    }

    {
        QHashIterator<QString, QLineSeries *>i(data_series);
        while(i.hasNext())
        {
            i.next();
            view_PID_Data->m_chart->removeSeries(i.value());
        }
        //最后把哈希表清空
        data_series.clear();
    }
}

void MainWindow::on_cB_mainwinBringToFront_clicked(bool checked)
{
    qDebug()<<"窗口置前："<<checked;
    if(checked)
    {
        this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//窗口总是显示在最前
        this->show();
    }
    else
    {
        this->setWindowFlags(this->windowFlags() &~ Qt::WindowStaysOnTopHint);//取消窗口总是显示在最前
        this->show();
    }
}



