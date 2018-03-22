#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Butterfly(QObject *parent = 0);
	void timerEvent(QTimerEvent *);	//定时器实现动画的原理是在定时器的timerEvent()中对QGraphicsItem进行重绘
	QRectF boundingRect() const;	//为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数

signals:

	public slots :
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	//重绘函数
private:
	bool up;	//用于标记蝴蝶翅膀的位置，以便实现动态效果
	QPixmap pix_up;            //用于表示两幅蝴蝶的图片
	QPixmap pix_down;

	qreal angle;
};

