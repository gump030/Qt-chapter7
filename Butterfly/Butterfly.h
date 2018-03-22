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
	void timerEvent(QTimerEvent *);	//��ʱ��ʵ�ֶ�����ԭ�����ڶ�ʱ����timerEvent()�ж�QGraphicsItem�����ػ�
	QRectF boundingRect() const;	//ΪͼԪ�޶�����Χ�����м̳���QGraphicsItem���Զ���ͼԪ������ʵ�ִ˺���

signals:

	public slots :
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	//�ػ溯��
private:
	bool up;	//���ڱ�Ǻ�������λ�ã��Ա�ʵ�ֶ�̬Ч��
	QPixmap pix_up;            //���ڱ�ʾ����������ͼƬ
	QPixmap pix_down;

	qreal angle;
};

