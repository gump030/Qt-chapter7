#pragma once

#include <QtWidgets/QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFrame>
#include "pixitem.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

	void createControlFrame();

private:
	int angle;
	qreal scaleValue;
	qreal shearValue;
	qreal translateValue;

	QGraphicsView *view;
	QFrame *ctrlFrame;
	PixItem *pixItem;
	public slots:
	void slotRotate(int);
	void slotScale(int);
	void slotShear(int);
	void slotTranslate(int);
};

