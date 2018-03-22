#include "MainWindow.h"
#include "flashitem.h"
#include "startitem.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	createActions();                    	//��������������ж���
	createMenus();                       	//����������Ĳ˵���
	createToolBar();
	scene = new QGraphicsScene;
	scene->setSceneRect(-200, -200, 400, 400);

	initScene();                         	//��ʼ������

	QGraphicsView *view = new QGraphicsView;
	view->setScene(scene);
	view->setMinimumSize(400, 400);
	view->show();

	setCentralWidget(view);
	resize(550, 450);
	setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()       	//��������������ж���
{
	newAct = new QAction(tr("�½�"), this);
	clearAct = new QAction(tr("���"), this);
	exitAct = new QAction(tr("�˳�"), this);
	addEllipseItemAct = new QAction(tr("���� ��Բ"), this);
	addPolygonItemAct = new QAction(tr("���� �����"), this);
	addTextItemAct = new QAction(tr("���� ����"), this);
	addRectItemAct = new QAction(tr("���� ������"), this);
	addAlphaItemAct = new QAction(tr("���� ͸��ͼƬ"), this);
	addFlashItemAct = new QAction(tr("���� ��˸Բ"), this);
	addAnimItemAct = new QAction(tr("���� ����"), this);

	connect(newAct, SIGNAL(triggered()), this, SLOT(slotNew()));
	connect(clearAct, SIGNAL(triggered()), this, SLOT(slotClear()));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
	connect(addEllipseItemAct, SIGNAL(triggered()), this, SLOT(slotAddEllipseItem()));
	connect(addPolygonItemAct, SIGNAL(triggered()), this, SLOT(slotAddPolygonItem()));
	connect(addTextItemAct, SIGNAL(triggered()), this, SLOT(slotAddTextItem()));
	connect(addRectItemAct, SIGNAL(triggered()), this, SLOT(slotAddRectItem()));
	connect(addAlphaItemAct, SIGNAL(triggered()), this, SLOT(slotAddAlphaItem()));
	connect(addFlashItemAct, SIGNAL(triggered()), this, SLOT(slotAddFlashItem()));
	connect(addAnimItemAct, SIGNAL(triggered()), this, SLOT(slotAddAnimationItem()));
}

void MainWindow::createMenus()         	//����������Ĳ˵���
{
	QMenu *fileMenu = menuBar()->addMenu(tr("�ļ�"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(clearAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);

	QMenu *itemsMenu = menuBar()->addMenu(tr("Ԫ��"));
	itemsMenu->addAction(addEllipseItemAct);
	itemsMenu->addAction(addPolygonItemAct);
	itemsMenu->addAction(addTextItemAct);
	itemsMenu->addAction(addRectItemAct);
	itemsMenu->addAction(addAlphaItemAct);
	itemsMenu->addAction(addFlashItemAct);
	itemsMenu->addAction(addAnimItemAct);
}

void MainWindow::createToolBar()
{
	toolBar = addToolBar("����");
	toolBar->addAction(addEllipseItemAct);
	toolBar->addAction(addPolygonItemAct);
	toolBar->addAction(addTextItemAct);
	toolBar->addAction(addRectItemAct);
	toolBar->addAction(addAlphaItemAct);
	toolBar->addAction(addFlashItemAct);
	toolBar->addAction(addAnimItemAct);
	toolBar->addSeparator();
	toolBar->addAction(newAct);
	toolBar->addAction(clearAct);
	toolBar->addAction(exitAct);
}

void MainWindow::initScene()        	//��ʼ������
{
	int i;
	for (i = 0; i<3; i++)
		slotAddEllipseItem();
	for (i = 0; i<3; i++)
		slotAddPolygonItem();
	for (i = 0; i<3; i++)
		slotAddTextItem();
	for (i = 0; i<3; i++)
		slotAddRectItem();
	for (i = 0; i<3; i++)
		slotAddAlphaItem();
	for (i = 0; i<3; i++)
		slotAddFlashItem();
	for (i = 0; i<3; i++)
		slotAddAnimationItem();
}

void MainWindow::slotNew()        		//�½�һ����ʾ����
{
	slotClear();
	initScene();

	MainWindow *newWin = new MainWindow;
	newWin->show();
}

void MainWindow::slotClear()        	//������������е�ͼԪ
{
	QList<QGraphicsItem*> listItem = scene->items();

	while (!listItem.empty())
	{
		scene->removeItem(listItem.at(0));
		listItem.removeAt(0);
	}
}

void MainWindow::slotAddEllipseItem() 	//�ڳ����м���һ����Բ��ͼԪ
{
	QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
	item->setPen(Qt::NoPen);
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);

	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddPolygonItem()   //�ڳ����м���һ�������ͼԪ
{
	QVector<QPoint> v;
	v << QPoint(30, -15) << QPoint(0, -30) << QPoint(-30, -15) << QPoint(-30, 15) << QPoint(0, 30) << QPoint(30, 15);
	QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);

	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddTextItem()      //�ڳ����м���һ������ͼԪ
{
	QFont font("Times", 16);
	QGraphicsTextItem *item = new QGraphicsTextItem("Hello Qt");
	item->setFont(font);
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setDefaultTextColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddRectItem()      //�ڳ����м���һ��������ͼԪ
{
	QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
	QPen pen;
	pen.setWidth(3);
	pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setPen(pen);
	item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
	item->setFlag(QGraphicsItem::ItemIsMovable);

	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAlphaItem()    	//�ڳ����м���һ��͸������ͼƬ
{
	QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("globe.png"));
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddFlashItem()  	//�ڳ����м���һ����˸ͼԪ
{
	FlashItem *item = new FlashItem;
	scene->addItem(item);
	item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAnimationItem() //�ڳ����м���һ����������
{
	StartItem *item = new StartItem;
	QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
	anim->setItem(item);
	QTimeLine *timeLine = new QTimeLine(4000);
	timeLine->setCurveShape(QTimeLine::SineCurve);
	timeLine->setLoopCount(0);

	anim->setTimeLine(timeLine);

	int y = (qrand() % 400) - 200;
	for (int i = 0; i<400; i++)
	{
		anim->setPosAt(i / 400.0, QPointF(i - 200, y));
	}
	timeLine->start();
	scene->addItem(item);
}
