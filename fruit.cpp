/*
 * File fruit.cpp
 * created on 2-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#include "fruit.h"
#include <block.h>
#include "snake.h"
#include <cstdio>

#include <iostream>

Fruit::Fruit(QWidget *parent,QSize ParentSize,Snake *snake):
	QFrame(parent)
{
	this->snake  = snake;
	this->ParentSize = ParentSize;


	QString style =
			"QFrame{"
			"	border-image:url(\":/img/apple.png\");"
			"};";
	setStyleSheet(style);
	setFixedSize(15,15);
	move(100,200);

}

void Fruit::Eaten()
{
	bool Maximized ;
	QPoint point;
	sos:
	Maximized = parentWidget()->windowState().testFlag(Qt::WindowMaximized);

	if(Maximized)
	{
		point.rx() = RandXY(0,ParentSize.width());
		point.ry() = RandXY(0,ParentSize.height());
	}
	else
	{
		point.rx() = RandXY(0,parentWidget()->geometry().width());
		point.ry() = RandXY(0,parentWidget()->geometry().height());
	}

	for(auto block :snake->blocks)
	{
		if(
		   (point.x() <= block->pos().x()+10 && point.x() >= block->pos().x()-10) &&
		   (point.y() <= block->pos().y()+10 && point.y() >= block->pos().y()-10)
		  )
			goto sos;
	}

	move(point);
}

int Fruit::RandXY(int min,int max)
{
	return min + (rand() % (max - min +1 ) );
}















