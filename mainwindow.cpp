/*
 * File mainwindow.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#include "mainwindow.h"
#include <QScreen>
#include <QGuiApplication>
#include <QFrame>

MainWindow::MainWindow():
	QMainWindow (nullptr)
{
	QString style =
		"QMainWindow{ "
		"background:url(\":/img/bg.png\");"
		"} ";

	QScreen *screen = QGuiApplication::primaryScreen();
	QRect  rect = screen->geometry();
	WinSize.setHeight(rect.height());
	WinSize.setWidth(rect.width());

	setWindowIcon(QIcon(":/img/icon.png"));

	setMaximumSize(WinSize);
	setMinimumSize(WinSize.width()*0.7,WinSize.height()*0.7);

	setStyleSheet(style);
	snake = new Snake(this,WinSize);
	fruit =  new Fruit(this,WinSize,snake);
	snake->setFruit(fruit);
	setCentralWidget(snake);
}

