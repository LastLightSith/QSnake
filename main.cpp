/*
 * File main.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#include <QApplication>
#include "mainwindow.h"

int main(int argc,char **argv)
{
	int code = 0;
	do{

	QApplication app(argc,argv);
	MainWindow win;
	win.showMaximized();
	code = app.exec();

	}while(code == 11117);
}
