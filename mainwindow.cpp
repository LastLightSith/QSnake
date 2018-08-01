/*
 * File mainwindow.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#include "mainwindow.h"

MainWindow::MainWindow():
	QMainWindow (nullptr)
{
	QString style =
		"QMainWindow{ "
		"background-image:url(\":/img/bg.png\");"
		" background-position: center;"
		"} ";

	setStyleSheet(style);
	snake = new Snake(this);
	setCentralWidget(snake);

}
