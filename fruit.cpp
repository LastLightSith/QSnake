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
#include <ctime>


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
	setFixedSize(20,20);
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
		point.rx() = RandXY(30,ParentSize.width()-30);
		point.ry() = RandXY(30,ParentSize.height())-30;
	}
	else
	{
		point.rx() = RandXY(30,parentWidget()->geometry().width());
		point.ry() = RandXY(30,parentWidget()->geometry().height());
	}

	for(auto block :snake->blocks)
	{
		if(
		   (point.x() <= block->pos().x()+30 && point.x() >= block->pos().x()-30) &&
		   (point.y() <= block->pos().y()+30 && point.y() >= block->pos().y()-30)
		  )
			goto sos;
	}

	move(point);
}

int Fruit::RandXY(int min,int max)
{
	srand(time(nullptr));
	return min + (rand() % (max - min +1 ) );
}















