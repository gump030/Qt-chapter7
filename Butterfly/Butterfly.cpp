#include "Butterfly.h"
#include <math.h>

const static double PI = 3.1416;

Butterfly::Butterfly(QObject *parent) :
	QObject(parent)
{
	up = true;
	pix_up.load("./image/Rotate90.png");
	pix_down.load("./image/Rotate180.png");

	startTimer(100);	//启动定时器，并设置时间间隔为100ms
}

QRectF Butterfly::boundingRect() const
{
	qreal adjust = 2;
	return QRectF(-pix_up.width() / 2 - adjust, -pix_up.height() / 2 - adjust, pix_up.width() + adjust * 2, pix_up.height() + adjust * 2);
}
/*判断当前已经显示的图片是pix_up还是pix_down,实现蝴蝶翅膀上下飞舞效果时，若当前现实的是pixup，则重绘pixdown图片，反之亦然*/
void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	if (up)
	{
		painter->drawPixmap(boundingRect().topLeft(), pix_up);
		up = !up;
	}
	else
	{
		painter->drawPixmap(boundingRect().topLeft(), pix_down);
		up = !up;
	}
}
//定时器的timeEvent（）实现图片的飞舞
void Butterfly::timerEvent(QTimerEvent *)
{
	//边界控制
	qreal edgex = scene()->sceneRect().right() + boundingRect().width() / 2;		//限定蝴蝶飞舞的右边界
	qreal edgetop = scene()->sceneRect().top() + boundingRect().height() / 2;		//限定蝴蝶飞舞的上边界
	qreal edgebottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;	//限定蝴蝶飞舞的下边界

	if (pos().x() >= edgex)
		setPos(scene()->sceneRect().left(), pos().y());		//若超出右边界，则水平移回左边界
	if (pos().y() <= edgetop)
		setPos(pos().x(), scene()->sceneRect().bottom());	//若超过上边界，则垂直移回下边界处
	if (pos().y() >= edgebottom)
		setPos(pos().x(), scene()->sceneRect().top());		//若超过了下边界，则垂直移回上边界处

	angle += (qrand() % 10) / 20.0;
	qreal dx = fabs(sin(angle*PI)*10.0);
	qreal dy = (qrand() % 20) - 10.0;

	setPos(mapToParent(dx, dy));
}
