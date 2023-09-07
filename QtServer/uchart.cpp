/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "uchart.h"
#include <QtGui/QResizeEvent>
#include <QtWidgets/QGraphicsScene>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtWidgets/QGraphicsTextItem>
#include "callout.h"
#include <QtGui/QMouseEvent>
#include "QDateTime"


UChart::UChart(QWidget *parent)
    : QGraphicsView(new QGraphicsScene, parent),
      m_coordX(0),
      m_coordY(0),
//      m_chart(0),
      m_tooltip(0)
{
//    axisX = new QValueAxis;
    axisX_Time = new QDateTimeAxis;
    axisY = new QValueAxis;

//    axisX->setRange(0,10);
    //设置时间轴的参数
    axisX_Time->setMin(QDateTime::currentDateTime().addSecs(-60*0.2));
    axisX_Time->setMax(QDateTime::currentDateTime().addSecs(0));
    axisX_Time->setTickCount(10);
    axisX_Time->setFormat("h:mm:ss:zzz");

    axisY->setRange(0,10);
//    axisX->setTickCount(10);
    axisY->setTickCount(10);

    setDragMode(QGraphicsView::NoDrag);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // chart
    m_chart = new QChart;
//    m_chart->setMinimumSize(640, 480);
//    m_chart->setTitle("Hover the line to show callout. Click the line to make it stay");
    m_chart->legend()->hide();

//    m_chart->createDefaultAxes();

//    m_chart->addAxis(axisX,Qt::AlignBottom);

    axisX_Time->setLabelsAngle(60);
    m_chart->addAxis(axisX_Time,Qt::AlignBottom);
    m_chart->addAxis(axisY, Qt::AlignLeft);

    m_chart->setAcceptHoverEvents(true);

    setRenderHint(QPainter::Antialiasing);
    scene()->addItem(m_chart);

    m_coordX = new QGraphicsSimpleTextItem(m_chart);
    m_coordX->setPos(m_chart->size().width()/2 - 50, m_chart->size().height());
    m_coordX->setText("X: ");
    m_coordY = new QGraphicsSimpleTextItem(m_chart);
    m_coordY->setPos(m_chart->size().width()/2 + 50, m_chart->size().height());
    m_coordY->setText("Y: ");

    this->setMouseTracking(true);

    //添加一个空序列
    QLineSeries *lineseries_2D_temp = new QLineSeries;
    m_chart->addSeries(lineseries_2D_temp);
    lineseries_2D_temp->attachAxis(axisX_Time);
    lineseries_2D_temp->attachAxis(axisY);
}

void UChart::resizeEvent(QResizeEvent *event)
{
    if (scene()) {
        scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
         m_chart->resize(event->size());
         m_coordX->setPos(m_chart->size().width()/2 - 50, m_chart->size().height() - 20);
         m_coordY->setPos(m_chart->size().width()/2 + 50, m_chart->size().height() - 20);
         const auto callouts = m_callouts;
         for (Callout *callout : callouts)
             callout->updateGeometry();
    }
    QGraphicsView::resizeEvent(event);
}

void UChart::mouseMoveEvent(QMouseEvent *event)
{
    QDateTime bjtime = QDateTime::currentDateTime();
    qreal x = m_chart->mapToValue(event->pos()).x();
//    qDebug()<<"时间："<<bjtime.fromMSecsSinceEpoch(x).toString(Qt::ISODateWithMs);
    QString m_time = "X: " + bjtime.fromMSecsSinceEpoch(x).toString(Qt::ISODateWithMs).mid(11,12);
    m_coordX->setText(m_time);
    m_coordY->setText(QString("Y: %1").arg(m_chart->mapToValue(event->pos()).y()));
    QGraphicsView::mouseMoveEvent(event);

    if(isRightBtnPressed)
    {
        QPoint pos = event->pos();
        QPoint oDeltaPos = pos - m_oPrePos;
        m_chart->scroll(-oDeltaPos.x(), oDeltaPos.y());
        m_oPrePos = pos;

    }
}

void UChart::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        qDebug()<<"右键按下";
        //当鼠标按下的时候，记录当前的鼠标坐标，作为移动视图的初始坐标
        m_oPrePos = event->pos();
        isRightBtnPressed = true;
    }
}

void UChart::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        qDebug()<<"右键松开";
        isRightBtnPressed = false;
    }
}

void UChart::wheelEvent(QWheelEvent *event)
{
    //滚轮事件
    if(event->angleDelta().y()>0)
    {
        qDebug()<<"鼠标滚轮事件：向前";
        m_chart->zoom(1.1);//大于1是放大，小于1是缩小

    }
    if(event->angleDelta().y()<0)
    {
        qDebug()<<"鼠标滚轮事件：向后";
        m_chart->zoom(0.9);//大于1是放大，小于1是缩小
    }
}

void UChart::keepCallout()
{
    m_callouts.append(m_tooltip);
    m_tooltip = new Callout(m_chart);
}

void UChart::tooltip(QPointF point, bool state)
{
    if (m_tooltip == 0)
        m_tooltip = new Callout(m_chart);

    if (state) {
        QDateTime bjtime = QDateTime::currentDateTime();
        qreal x = point.x();
    //    qDebug()<<"时间："<<bjtime.fromMSecsSinceEpoch(x).toString().mid(10,8);
        QString m_time = "X:" + bjtime.fromMSecsSinceEpoch(x).toString(Qt::ISODateWithMs).mid(11,12);

//        m_tooltip->setText(QString("X: %13 \nY: %2 ").arg(point.x()).arg(point.y()));
        m_tooltip->setText(m_time + "\nY:" + QString::number(point.y()));
        m_tooltip->setAnchor(point);
        m_tooltip->setZValue(11);
        m_tooltip->updateGeometry();
        m_tooltip->show();
    } else {
        m_tooltip->hide();
    }
}
