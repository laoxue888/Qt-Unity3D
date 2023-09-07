#ifndef TCPWORKER_H
#define TCPWORKER_H

#include "QObject"
#include "QThread"

#include "QTcpServer"
#include "QTcpSocket"
#include "QDebug"

class QTcpServer;//前向声明
class QTcpSocket;


class TcpWorker : public QObject //继承QObject
{
    Q_OBJECT //添加这个才可以添加信号与槽机制
public:
    explicit TcpWorker(QTcpServer *tcp, QObject *parent = nullptr);


private:
    QTcpServer *tcpServer;//用来接收构造函数传进来的对象，服务器端
    QTcpSocket *clientTcpSocket; //客户端socket

    //状态信息，发送给GUI
    QString statusText;

public:
    bool isConnected = false;
    void SocketSend(QString sendStr);
signals:
    void TcpStatusMessage(QString statusText);
    void sendDataToGUI(QHash<QString, double> parseData);

public slots:
    void SocketConnect();
    void SocketDisconnect();
    void SocketReceive();

};

#endif // TCPWORKER_H

