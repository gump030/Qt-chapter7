#include "Butterfly.h"
#include <math.h>

const static double PI = 3.1416;

Butterfly::Butterfly(QObject *parent) :
	QObject(parent)
{
	up = true;
	pix_up.load("./image/Rotate90.png");
	pix_down.load("./image/Rotate180.png");

	startTimer(100);	//������ʱ����������ʱ����Ϊ100ms
}

QRectF Butterfly::boundingRect() const
{
	qreal adjust = 2;
	return QRectF(-pix_up.width() / 2 - adjust, -pix_up.height() / 2 - adjust, pix_up.width() + adjust * 2, pix_up.height() + adjust * 2);
}
/*�жϵ�ǰ�Ѿ���ʾ��ͼƬ��pix_up����pix_down,ʵ�ֺ���������·���Ч��ʱ������ǰ��ʵ����pixup�����ػ�pixdownͼƬ����֮��Ȼ*/
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
//��ʱ����timeEvent����ʵ��ͼƬ�ķ���
void Butterfly::timerEvent(QTimerEvent *)
{
	//�߽����
	qreal edgex = scene()->sceneRect().right() + boundingRect().width() / 2;		//�޶�����������ұ߽�
	qreal edgetop = scene()->sceneRect().top() + boundingRect().height() / 2;		//�޶�����������ϱ߽�
	qreal edgebottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;	//�޶�����������±߽�

	if (pos().x() >= edgex)
		setPos(scene()->sceneRect().left(), pos().y());		//�������ұ߽磬��ˮƽ�ƻ���߽�
	if (pos().y() <= edgetop)
		setPos(pos().x(), scene()->sceneRect().bottom());	//�������ϱ߽磬��ֱ�ƻ��±߽紦
	if (pos().y() >= edgebottom)
		setPos(pos().x(), scene()->sceneRect().top());		//���������±߽磬��ֱ�ƻ��ϱ߽紦

	angle += (qrand() % 10) / 20.0;
	qreal dx = fabs(sin(angle*PI)*10.0);
	qreal dy = (qrand() % 20) - 10.0;

	setPos(mapToParent(dx, dy));
}
