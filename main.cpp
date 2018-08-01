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
	QApplication app(argc,argv);
	MainWindow win;
	win.show();
	return app.exec();
}
