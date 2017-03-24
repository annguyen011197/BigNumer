#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include "Qintnum.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	private slots:
	void clear();
	void add();
	void subtract();
	void mutiply();
	void divide();
	void equal();
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	void zero();
	void mod();
	void clearall();
	QString val();
	bool testVal();
	void uz();
	QString html(QString);
	void testUz();
	void equalclear();
	void bina();
	void hex();
	void testValue();
private:
	QTextBrowser *result;
	QTextBrowser *textValue;
	QPushButton *clear_all_button;
	QPushButton *mod_button;
	QPushButton *clear_button;
	QPushButton *add_button;
	QPushButton *subtract_button;
	QPushButton *mutiply_button;
	QPushButton *divide_button;
	QPushButton *equal_button;
	QPushButton *one_button;
	QPushButton *two_button;
	QPushButton *three_button;
	QPushButton *four_button;
	QPushButton *five_button;
	QPushButton *six_button;
	QPushButton *seven_button;
	QPushButton *eight_button;
	QPushButton *nine_button;
	QPushButton *zero_button;
	QPushButton *uz_button;
	QPushButton *bin_button;
	QPushButton *hex_button;
};

#endif // MAINWINDOW_H
