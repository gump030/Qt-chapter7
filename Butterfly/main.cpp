#include "Butterfly.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Butterfly w;
	w.show();
	return a.exec();
}
