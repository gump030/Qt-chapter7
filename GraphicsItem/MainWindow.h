#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
#include <qtoolbar.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	void initScene();            			//��ʼ������
	void createActions();       			//��������������ж���
	void createMenus();         			//����������Ĳ˵���
	void createToolBar();

	public slots:
	void slotNew();              			//�½�һ����ʾ����
	void slotClear();           			//������������е�ͼԪ

	void slotAddEllipseItem();              //�ڳ����м���һ����Բ��ͼԪ
	void slotAddPolygonItem();      		//�ڳ����м���һ�������ͼԪ
	void slotAddTextItem();         		//�ڳ����м���һ������ͼԪ
	void slotAddRectItem();         		//�ڳ����м���һ��������ͼԪ
	void slotAddAlphaItem();        		//�ڳ����м���һ��͸������ͼƬ
	void slotAddFlashItem();
	void slotAddAnimationItem();

private:
	QGraphicsScene * scene;

	QToolBar *toolBar;
	QAction *newAct;
	QAction *clearAct;
	QAction *exitAct;
	QAction *addEllipseItemAct;
	QAction *addPolygonItemAct;
	QAction *addTextItemAct;
	QAction *addRectItemAct;
	QAction *addAlphaItemAct;
	QAction *addFlashItemAct;
	QAction *addAnimItemAct;
};