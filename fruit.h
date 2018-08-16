/*
 * File fruit.h
 * created on 2-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#ifndef FRUIT_H
#define FRUIT_H

#include <QFrame>
#include <QSize>

class Snake;

class Fruit:public QFrame
{
public:
	Fruit(QWidget *parent,QSize Parentsize,Snake *snake);
	void Eaten();

private:
	QSize ParentSize;
	Snake *snake;
	int RandXY(int min,int max);

};

#endif // FRUIT_H
