/*
 * File Snake.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#include "snake.h"
#include "block.h"
#include <QKeyEvent>
#include <QTimer>
#include <QPoint>
#include <iostream>
#include "mainwindow.h"


QSize *Snake::BlockSize;

Snake::Snake(QWidget *Parent,QSize ParentSize):
	QWidget(Parent),
	timer(new QTimer(this))
{
	BlockSize = new QSize(15,15);
	this->ParentSize = ParentSize;

	push(new Block(this));
	push(new Block(this));
	push(new Block(this));
	push(new Block(this));
	push(new Block(this));

	connect(timer,SIGNAL(timeout()),SLOT(Crawl()));
	timer->start(50);

	setFocus();
	grabKeyboard();

}

void Snake::push(Block *b )
{
	QPoint p;
	if(!blocks.size())
	{
		b->move(00,00);
		blocks.push_back(b);
		return;
	}
	else
		p = blocks[blocks.size()-1]->pos();
	QPoint des;
	switch (b->BlockDirection)
	{
		case LEFT:
			des.setX(p.x()-BlockSize->width()-1);
			des.setY(p.y());
			break;
		case RIGHT:
			des.setX(p.x()+BlockSize->width()+1);
			des.setY(p.y());
			break;
		case DOWN:
			des.setY(p.y()+BlockSize->width()+1);
			des.setX(p.x());
			break;
		case UP:
			des.setY(p.y()-BlockSize->width()-1);
			des.setX(p.x());
			break;
	}
	b->move(des);

	blocks.push_back(b);
}

void Snake::keyPressEvent(QKeyEvent *e)
{
	switch(e->key())
	{
		case Qt::Key_W:
		case Qt::Key_Up:
			d = UP;
			break;

		case Qt::Key_A:
		case Qt::Key_Left:
			d = LEFT;
			break;

		case Qt::Key_Down:
		case Qt::Key_S:
			d = DOWN;
			break;

		case Qt::Key_D:
		case Qt::Key_Right:
			d = RIGHT;
			break;
	}

	std::cout << e->text().toStdString() << " has been pressed\n";
}


void Snake::Crawl()
{
	QPoint p = blocks.at(0)->pos();
	QPoint des;

	bool screencross = false;

	bool Maximizd = parentWidget()->windowState().testFlag(Qt::WindowMaximized);
	if(Maximizd)
	{
		if(p.x() > ParentSize.width())
		{
			des.setX(0);
			des.setY(p.y());
			screencross = true;
		}
		if(p.y() > ParentSize.height())
		{
			des.setY(0);
			des.setX(p.x());
			screencross = true;
		}

		if(!(p.x() > -1))
		{
			des.setX(ParentSize.width());
			des.setY(p.y());
			screencross = true;
		}
		if(!(p.y() > -1))
		{
			des.setY(ParentSize.height());
			des.setX(p.x());
			screencross = true;
		}
	}
	else
	{
		if(p.x() >  parentWidget()->geometry().width())
		{
			des.setX(0);
			des.setY(p.y());
			screencross = true;
		}
		if(p.y() > parentWidget()->geometry().height())
		{
			des.setY(0);
			des.setX(p.x());
			screencross = true;
		}

		if(!(p.x() > -1))
		{
			des.setX(parentWidget()->width());
			des.setY(p.y());
			screencross = true;
		}
		if(!(p.y() > -1))
		{
			des.setY(parentWidget()->height());
			des.setX(p.x());
			screencross = true;
		}

	}
	if(!screencross)
		switch (d)
		{
			case LEFT:
				des.setX(p.x()-BlockSize->width()-1);
				des.setY(p.y());
				break;
			case RIGHT:
				des.setX(p.x()+BlockSize->width()+1);
				des.setY(p.y());
				break;
			case DOWN:
				des.setY(p.y()+BlockSize->width()+1);
				des.setX(p.x());
				break;
			case UP:
				des.setY(p.y()-BlockSize->width()-1);
				des.setX(p.x());
				break;
		}

	blocks[0]->move(des);

	for(uint i=1;i<blocks.size();i++)
	{
		des = blocks[i]->pos();
		blocks[i]->move(p);
		p=des;
	}
	std::cout << "Crawl funtion has been called\n";
}















































