/*
 * File t.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snake.h"

class MainWindow : public QMainWindow
{
public:
	MainWindow();
private:
	Snake* snake;

};

#endif // MAINWINDOW_H
