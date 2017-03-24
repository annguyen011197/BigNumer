#include "mainwindow.h"
#include <string>
QString num_style = "background-color: rgb(179, 255, 255); color: rgb(0,0,0); font: bold 14px;",
uz_style = "background-color: rgb(51, 51, 204); color: rgb(255, 255, 255); font: bold 14px;",
function_style = "background-color: rgb(191, 191, 191); color: rgb(255, 255, 255); font: bold 14px;",
delete_style = "background-color: rgb(51, 119, 255); color: rgb(255, 51, 51); font: bold 14px;",
equal_style = "background-color: rgb(255, 0, 0); color: rgb(255, 255, 255); font: bold 14px;";
bool addBool = 0, subBool = 0, mutiBool = 0, divBool = 0, modBool = 0, binBool = 0, hexBool =0;

QString value = "", total = "", fNum = "", sNum = "", rTotal="";

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	result = new QTextBrowser(this);
	result->setGeometry(QRect(QPoint(15, 15), QSize(320, 100))); //Show phep tinh
	result->setHtml(html("0"));

	textValue = new QTextBrowser(this);
	textValue->setGeometry(QRect(QPoint(15, 115), QSize(320, 50))); //Show nhap va ket qua
	textValue->setHtml(html("0"));

	 clear_all_button = new QPushButton("CE", this);
	 clear_all_button->setGeometry(QRect(QPoint(175, 350), QSize(50, 50)));
	 clear_all_button->setStyleSheet(delete_style);
	 connect(clear_all_button, SIGNAL(released()), this, SLOT(clearall()));

	 mod_button = new QPushButton("mod", this);
	 mod_button->setGeometry(QRect(QPoint(225, 300), QSize(50, 50)));
	 mod_button->setStyleSheet(function_style);
	 connect(mod_button, SIGNAL(released()), this, SLOT(mod()));

	 clear_button = new QPushButton("C", this);
	 clear_button->setGeometry(QRect(QPoint(175, 300), QSize(50, 50)));
	 clear_button->setStyleSheet(delete_style);
	 connect(clear_button, SIGNAL(released()), this, SLOT(clear()));

	 add_button = new QPushButton("+", this);
	 add_button->setGeometry(QRect(QPoint(175, 200), QSize(50, 50)));
	 add_button->setStyleSheet(function_style);
	 connect(add_button, SIGNAL(released()), this, SLOT(add()));

	 subtract_button = new QPushButton("-", this);
	 subtract_button->setGeometry(QRect(QPoint(225, 200), QSize(50, 50)));
	 subtract_button->setStyleSheet(function_style);
	 connect(subtract_button, SIGNAL(released()), this, SLOT(subtract()));

	 mutiply_button = new QPushButton("x", this);
	 mutiply_button->setGeometry(QRect(QPoint(175, 250), QSize(50, 50)));
	 mutiply_button->setStyleSheet(function_style);
	 connect(mutiply_button, SIGNAL(released()), this, SLOT(mutiply()));

	 divide_button = new QPushButton("div", this);
	 divide_button->setGeometry(QRect(QPoint(225, 250), QSize(50, 50)));
	 divide_button->setStyleSheet(function_style);
	 connect(divide_button, SIGNAL(released()), this, SLOT(divide()));

	 equal_button = new QPushButton("=", this);
	 equal_button->setGeometry(QRect(QPoint(225, 350), QSize(50, 50)));
	 equal_button->setStyleSheet(equal_style);
	 connect(equal_button, SIGNAL(released()), this, SLOT(equal()));

	 one_button = new QPushButton("1", this);
	 one_button->setGeometry(QRect(QPoint(15, 200), QSize(50, 50)));
	 one_button->setStyleSheet(num_style);
	 connect(one_button, SIGNAL(released()), this, SLOT(one()));

	 two_button = new QPushButton("2", this);
	 two_button->setGeometry(QRect(QPoint(65, 200), QSize(50, 50)));
	 two_button->setStyleSheet(num_style);
	 connect(two_button, SIGNAL(released()), this, SLOT(two()));

	 three_button = new QPushButton("3", this);
	 three_button->setGeometry(QRect(QPoint(115, 200), QSize(50, 50)));
	 three_button->setStyleSheet(num_style);
	 connect(three_button, SIGNAL(released()), this, SLOT(three()));

	 four_button = new QPushButton("4", this);
	 four_button->setGeometry(QRect(QPoint(15, 250), QSize(50, 50)));
	 four_button->setStyleSheet(num_style);
	 connect(four_button, SIGNAL(released()), this, SLOT(four()));

	 five_button = new QPushButton("5", this);
	 five_button->setGeometry(QRect(QPoint(65, 250), QSize(50, 50)));
	 five_button->setStyleSheet(num_style);
	 connect(five_button, SIGNAL(released()), this, SLOT(five()));

	 six_button = new QPushButton("6", this);
	 six_button->setGeometry(QRect(QPoint(115, 250), QSize(50, 50)));
	 six_button->setStyleSheet(num_style);
	 connect(six_button, SIGNAL(released()), this, SLOT(six()));

	 seven_button = new QPushButton("7", this);
	 seven_button->setGeometry(QRect(QPoint(15, 300), QSize(50, 50)));
	 seven_button->setStyleSheet(num_style);
	 connect(seven_button, SIGNAL(released()), this, SLOT(seven()));

	 eight_button = new QPushButton("8", this);
	 eight_button->setGeometry(QRect(QPoint(65, 300), QSize(50, 50)));
	 eight_button->setStyleSheet(num_style);
	 connect(eight_button, SIGNAL(released()), this, SLOT(eight()));

	 nine_button = new QPushButton("9", this);
	 nine_button->setGeometry(QRect(QPoint(115, 300), QSize(50, 50)));
	 nine_button->setStyleSheet(num_style);
	 connect(nine_button, SIGNAL(released()), this, SLOT(nine()));

	 zero_button = new QPushButton("0", this);
	 zero_button->setGeometry(QRect(QPoint(65, 350), QSize(50, 50)));
	 zero_button->setStyleSheet(num_style);
	 connect(zero_button, SIGNAL(released()), this, SLOT(zero()));

	 uz_button = new QPushButton("-( )", this);
	 uz_button->setGeometry(QRect(QPoint(115, 350), QSize(50, 50)));
	 uz_button->setStyleSheet(uz_style);
	 connect(uz_button, SIGNAL(released()), this, SLOT(uz()));

	 bin_button = new QPushButton("Bin", this);
	 bin_button->setGeometry(QRect(QPoint(275, 250), QSize(50, 50)));
	 bin_button->setStyleSheet(function_style);
	 connect(bin_button, SIGNAL(released()), this, SLOT(bina()));

	 hex_button = new QPushButton("Hex", this);
	 hex_button->setGeometry(QRect(QPoint(275, 300), QSize(50, 50)));
	 hex_button->setStyleSheet(function_style);
	 connect(hex_button, SIGNAL(released()), this, SLOT(hex()));
}

void MainWindow::clear(){
	value = "";
	textValue->setHtml(html(value));
	total = rTotal;
	result->setHtml(html(total));
}
void MainWindow::add(){
	if ( (!hexBool) && (!binBool)) {
		total += "+";
	}
	else {
		total = rTotal + "+";
		binBool = 0;
		hexBool = 0;
	}
	rTotal = total;
	result->setHtml(html(total));
	if (addBool || subBool || mutiBool || divBool || modBool ) {
		fNum = val();
		sNum = "";
		value = "";
		textValue->setHtml(html(fNum));
		addBool = 1;
	}
	else if (!addBool) {
		fNum = value;
		value = "";
		textValue->setHtml(html("0"));
		addBool = 1;
	}
	testUz();
}
void MainWindow::subtract(){
	if (!binBool && !hexBool) {
		total += "-";
	}
	else {
		total = rTotal + "-";
		binBool = 0;
		hexBool = 0;
	}
	rTotal = total;
	result->setHtml(html(total));
	if (addBool || subBool || mutiBool || divBool || modBool) {
		fNum = val();
		sNum = "";
		value = "";
		textValue->setHtml(html(fNum));
		subBool = 1;
	}
	else if (!subBool) {
		fNum = value;
		value = "";
		textValue->setHtml(html("0"));
		subBool = 1;
	}
	testUz();
}
void MainWindow::mutiply(){
	if (!binBool && !hexBool) {
		total = "(" + total + ")x";
	}
	else {
		total = "(" + rTotal + ")x";
		binBool = 0;
		hexBool = 0;
	}

	rTotal = total;
	result->setHtml(html(total));
	if (addBool || subBool || mutiBool || divBool || modBool) {
		fNum = val();
		sNum = "";
		value = "";
		textValue->setHtml(html(fNum));
		mutiBool = 1;
	}
	else if (!mutiBool) {
		fNum = value;
		value = "";
		textValue->setHtml(html("0"));
		mutiBool = 1;
	}
	testUz();
}
void MainWindow::divide(){
	if (!binBool && !hexBool) {
		total = "(" + total + ")/";
	}
	else {
		total = "(" + rTotal + ")/";
		binBool = 0;
		hexBool = 0;
	}
	rTotal = total;
	result->setHtml(html(total));
	if (addBool || subBool || mutiBool || divBool || modBool) {
		fNum = val();
		sNum = "";
		value = "";
		textValue->setHtml(html(fNum));
		divBool = 1;
	}
	else if (!divBool) {
		fNum = value;
		value = "";
		textValue->setHtml(html("0"));
		divBool = 1;
	}
	testUz();
}
void MainWindow::mod() {
	if (!binBool && !hexBool) {
		total = "(" + total + ")%";
	}
	else {
		total = "(" + rTotal + ")%";
		binBool = 0;
		hexBool = 0;
	}
	rTotal = total;
	result->setHtml(html(total));
	if (addBool || subBool || mutiBool || divBool || modBool) {
		fNum = val();
		sNum = "";
		value = "";
		textValue->setHtml(html(fNum));
		modBool = 1;
	}
	else if (!modBool) {
		fNum = value;
		value = "";
		textValue->setHtml(html("0"));
		modBool = 1;
	}
	testUz();
}
void MainWindow::equal(){
	sNum = value;
	if (addBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 + Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	if (subBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 - Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	if (mutiBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 * Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	if (divBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 / Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	if (modBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 % Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	equalclear();
}
void MainWindow::one(){
	value += "1";
	total += "1";
	rTotal += "1";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::two(){
	value += "2";
	total += "2";
	rTotal += "2";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::three(){
	value += "3";
	total += "3";
	rTotal += "3";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::four(){
	value += "4";
	total += "4";
	rTotal += "4";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::five(){
	value += "5";
	total += "5";
	rTotal += "5";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::six(){
	value += "6";
	total += "6";
	rTotal += "6";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::seven(){
	value += "7";
	total += "7";
	rTotal += "7";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::eight(){
	value += "8";
	total += "8";
	rTotal += "8";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::nine(){
	value += "9";
	total += "9";
	rTotal += "9";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}
void MainWindow::zero(){
	value += "0";
	total += "0";
	rTotal += "0";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	testUz();
	testValue();
}

void MainWindow::clearall(){
	addBool = 0;
	subBool = 0;
	mutiBool = 0; 
	divBool = 0;
	modBool = 0;
	binBool = 0;
	fNum = "";
	sNum = "";
	value = "";
	total = "";
	rTotal = "";
	textValue->setHtml(html("0"));
	result->setHtml(html("0"));
	testUz();
}
QString MainWindow::val() { 
	sNum = value;
	if (addBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 + Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		addBool = 0;
	}
	if (subBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 - Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		subBool = 0;
	}
	if (mutiBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 * Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		mutiBool = 0;
	}
	if (divBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 / Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		divBool = 0;
	}
	if (modBool) {
		string qNum1 = fNum.toStdString();
		string qNum2 = sNum.toStdString();
		Qintnum Q1 = Q1.decStringToQintnum(qNum1);
		Qintnum Q2 = Q2.decStringToQintnum(qNum2);
		Qintnum Q3 = Q3 = Q1 % Q2;
		string qNum3 = "";
		Q3.toDecString(qNum3);
		QString qNum = QString::fromStdString(qNum3);
		value = qNum;
		textValue->setHtml(html(value));
		modBool = 0;
	}
	return value; }
bool MainWindow::testVal() { return 1; }
void MainWindow::uz(){
	value += "-";
	total += "-";
	result->setHtml(html(total));
	textValue->setHtml(html(value));
	uz_button->setEnabled(0);
}
QString MainWindow::html(QString text){ 
	return "<p style=\"font-size:15pt;\">" +text+"</p>"; }
void MainWindow::testUz(){
	string s = "";
	s = rTotal.toStdString();
	if (value == "" )
		uz_button->setEnabled(1);
	else
		uz_button->setEnabled(0);

}
void MainWindow::equalclear(){
	addBool = 0;
	subBool = 0;
	mutiBool = 0;
	divBool = 0;
	modBool = 0;
	hexBool = 0;
	fNum = "";
	sNum = "";
}
void MainWindow::bina(){
	fNum = value;
	string s = "";
	s = fNum.toStdString();
	Qintnum Q3 = Q3.decStringToQintnum(s);
	s = Q3.getBitSet().to_string();
	QString s1 = QString::fromStdString(s);
	total = s1;
	result->setHtml(html(total));
	binBool = 1;
}
void MainWindow::hex(){
	fNum = value;
	string s = "";
	s = fNum.toStdString();
	Qintnum Q3 = Q3.decStringToQintnum(s);
	s = Q3.toHexString();
	QString s1 = QString::fromStdString(s);
	total = s1;
	result->setHtml(html(total));
	hexBool = 1;
}

void MainWindow::testValue() {
	string s = "";
	s = value.toStdString();
	if (s.size() > 30) {
		total = QString::fromUtf8("Da qua gioi han!");
		result->setHtml("<p style=\"font-size:15pt; color:red; \">" + total + "</p>");
		one_button->setEnabled(0);
		two_button->setEnabled(0);
		three_button->setEnabled(0);
		four_button->setEnabled(0);
		five_button->setEnabled(0);
		six_button->setEnabled(0);
		seven_button->setEnabled(0);
		eight_button->setEnabled(0);
		nine_button->setEnabled(0);
		zero_button->setEnabled(0);
		uz_button->setEnabled(0);
		bin_button->setEnabled(0);
		hex_button->setEnabled(0);
		add_button->setEnabled(0);
		subtract_button->setEnabled(0);
		mutiply_button->setEnabled(0);
		mod_button->setEnabled(0);
		divide_button->setEnabled(0);
		equal_button->setEnabled(0);
	}
	else {
		one_button->setEnabled(1);
		two_button->setEnabled(1);
		three_button->setEnabled(1);
		four_button->setEnabled(1);
		five_button->setEnabled(1);
		six_button->setEnabled(1);
		seven_button->setEnabled(1);
		eight_button->setEnabled(1);
		nine_button->setEnabled(1);
		zero_button->setEnabled(1);
		bin_button->setEnabled(1);
		hex_button->setEnabled(1);
		add_button->setEnabled(1);
		subtract_button->setEnabled(1);
		mutiply_button->setEnabled(1);
		mod_button->setEnabled(1);
		divide_button->setEnabled(1);
		equal_button->setEnabled(1);
	}
}

MainWindow::~MainWindow()
{

}
