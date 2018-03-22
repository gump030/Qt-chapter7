#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Butterfly.h"

class Butterfly : public QMainWindow
{
	Q_OBJECT

public:
	Butterfly(QWidget *parent = Q_NULLPTR);

private:
	Ui::ButterflyClass ui;
};
