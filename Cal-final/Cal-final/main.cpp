#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <qdesktopwidget.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized();
	w.setFixedSize(350, 450);
	w.move(QApplication::desktop()->screen()
		->rect().center() - w.rect().center());
	w.show();
	return a.exec();
}
