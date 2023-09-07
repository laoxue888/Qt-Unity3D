#include "tcpworker.h"

/*
 * 功能：TcpWorker类的构造函数
 */
TcpWorker::TcpWorker(QTcpServer *tcp,QObject *parent) : QObject(parent),tcpServer(tcp)
{
    if(!tcpServer->listen(QHostAddress::Any,6666)) //监听所有网络地址，端口6666
        qDebug()<<tcpServer->errorString();
    connect(tcpServer,&QTcpServer::newConnection,this,&TcpWorker::SocketConnect);

}

/*
 * 功能：构建tcp连接
 */
void TcpWorker::SocketConnect()
{
    //获得client socket
    clientTcpSocket = tcpServer->nextPendingConnection();
    //绑定信号槽，接收数据，并且当连接关闭是删除连接
    connect(clientTcpSocket,&QTcpSocket::readyRead,this,&TcpWorker::SocketReceive);
//    connect(clientTcpSocket,&QTcpSocket::disconnected,clientTcpSocket,&QTcpSocket::deleteLater);
    connect(clientTcpSocket,&QTcpSocket::disconnected,this,&TcpWorker::SocketDisconnect);

    //显示客户端连接信息
    QString clientIp = clientTcpSocket->peerAddress().toString();
    QString clientPort=QString::number(clientTcpSocket->peerPort());
    QString statusText = "已连接：IP("+ clientIp + "):Port(" + clientPort + ")\n";

    isConnected = true;
    emit TcpStatusMessage(statusText);
}

/*
 * 功能：断开tcp连接
 */
void TcpWorker::SocketDisconnect()
{
//    qDebug()<<"已经断开连接";
    emit TcpStatusMessage("已经断开连接");
    isConnected = false;
}

/*
 * 功能：通过tcp发送数据
 */
void TcpWorker::SocketSend(QString sendStr)
{
    clientTcpSocket->write(sendStr.toStdString().c_str());
}

/*
 * 功能：tcp接收数据
 */
void TcpWorker::SocketReceive()
{
    //接收数据并显示，字节转换成了字符串
    QString recvStr = clientTcpSocket->readAll(); //这个函数肯定需要放到子线程上
//    emit TcpStatusMessage(recvStr);
    qDebug()<<"子线程接收到的数据：" << recvStr;

    static QString test_buffer;
    test_buffer.append(recvStr);
    qDebug() << "缓存数据："<<test_buffer;

    //寻找第1个帧头的位置
    QString frame_heads[] = {"2022Aa1xxx"};
    int index1 = -1;  //找第一个帧头的位置
    QList<int> temp1; //创建容器
    for(int i =0 ; i < 1; i++ ) //frame_heads有3个元素，但是for循环执行4次
    {
        int pos = test_buffer.indexOf(frame_heads[i],0);
        qDebug() << "帧头1："<< i << "："<<frame_heads[i];
//        qDebug() << "第1个帧头位置："<< i << "："<<pos;
        if(pos != -1)
        {
            temp1.append(pos);
        }
    }
    //取在最前面的帧头
    if(temp1.count()>0)
    {
        index1 = temp1.at(0); //取第一个
        foreach(int each, temp1)
        {
            if(index1 >= each)
                index1 = each;
        }
    }

    //如果找不到，退出函数
    if(index1==-1)
    {
        return;
    }

    qDebug() << "第1个帧头位置："<<index1; //这个不能注释掉，否则信号发送不出去

    //删除数据  remove(int pos, int len)， 这里删除前一组数据，而不是清空缓存
    if(index1>=0)
    {
        test_buffer.remove(0, index1);
    }

    //寻找第二个帧头位置
    int index2 = -1;
    QList<int> temp2; //创建int类型的列表
    for(int i =0 ; i < 1;i++ )
    {
        int pos = test_buffer.indexOf(frame_heads[i],4);
//        qDebug() << "帧头2："<< i << "："<<frame_heads[i];
//        qDebug() << "第2个帧头位置："<< i << "："<< pos;
        if(pos != -1)
        {
            temp2.append(pos);  //还有一个问题，当存在3帧以上怎么办，（目前了解，只能同时出现3帧）
        }
    }
    //取在最前面的帧头
    if(temp2.count()>0)
    {
        index2 = temp2.at(0); //取第一个
        foreach(int each, temp2)
        {
            if(index2 >= each)
                index2 = each;
        }
    }

    qDebug() << "第2个帧头位置："<<index2; //这个不能注释掉，否则信号发送不出去

    if(index2!=-1) //当存在第2个帧头时，再删数据
    {
        //提取帧数据
        QString frame_Data = test_buffer.mid(0, index2);

        qDebug() << "所要的帧数据："<< frame_Data;
        /****************数据解算****************/

        //透传数据解析，帧头是2022Aa1xxx
        if(frame_Data.startsWith("2022Aa1xxx"))
        {
            //去头去尾
            frame_Data.remove(0,10);
            frame_Data.remove(frame_Data.count() - 3,frame_Data.count());
//            qDebug() << "帧数据："<< frame_Data;

            //数据解析
            QStringList dataList = frame_Data.split("::");
//            qDebug() << "帧数据："<< dataList;//QList("angleVelX:-0.3663963", "angleVelY:-0.9223034", "angleVelZ:-0.4284636", "QuadHeight:1.115209")
            QHash<QString, double> parseData;
            for(int i = 0; i < dataList.size();i++)
            {
                QStringList dataList_temp = dataList.at(i).split(":");
                parseData.insert(dataList_temp.at(0), dataList_temp.at(1).toDouble());
            }
            qDebug() << "解析数据："<< parseData;
            emit sendDataToGUI(parseData);
        }

        //IMU数据解析，帧头是2022Aa2xxx
        if(frame_Data.startsWith("2022Aa2xxx"))
        {

        }

        test_buffer.remove(0, index2);//删除数据
    }

    //防止缓存出现问题
    if(test_buffer.count() > 400)
    {
        qDebug() << "缓存过大，需要清理";
        test_buffer.clear();
    }

}
