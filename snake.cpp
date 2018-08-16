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
#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

#include <iostream>
#include <unistd.h>

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
	timer->start(speed);

	setFocus();
	grabKeyboard();

}

void Snake::push(Block *b , Direction pd)
{
	QPoint p;
	if(!blocks.size())
	{
		b->move(130,130);
		blocks.push_back(b);
		return;
	}
	else
		p = blocks[blocks.size()-1]->pos();
	QPoint des;
	switch (pd)
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
			if(d!=DOWN)
				d = UP;
			break;

		case Qt::Key_A:
		case Qt::Key_Left:
			if(d!=RIGHT)
				d = LEFT;
			break;

		case Qt::Key_Down:
		case Qt::Key_S:
			if(d!=UP)
				d = DOWN;
			break;

		case Qt::Key_D:
		case Qt::Key_Right:
			if(d!=LEFT)
				d = RIGHT;
			break;
	}

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

	Block *temp = blocks[blocks.size()-1];
	temp->move(des);
	blocks.pop_back();
	blocks.insert(blocks.begin(),temp);

	if(
	   (blocks[0]->pos().x() <= fruit->pos().x()+10 && blocks[0]->pos().x() >= fruit->pos().x()-10) &&
	   (blocks[0]->pos().y() <= fruit->pos().y()+10 && blocks[0]->pos().y() >= fruit->pos().y()-10)
	  )
	{
		fruit->Eaten();
		Block *New;
		for(int i = 0;i<8;i++)
		{
			New = new Block(this);
			New->move(blocks[blocks.size()-1]->pos());
			blocks.push_back(New);
		}
	}

	CheckHead();
}

void Snake::setFruit(Fruit *fruit)
{
	this->fruit = fruit;
}

void Snake::CheckHead()
{
	bool hited  = false;
	for(uint i=2;i<blocks.size();i++)
	{
		if(blocks[i]->pos() == blocks[0]->pos())
			hited = true;
	}

	if(hited)
	{

		timer->stop();

		QWidget *hit  = new QWidget();
		QGridLayout *grid = new QGridLayout();
		hit->setLayout(grid);
		QLabel *label = new QLabel("Opps ! You hit youself !!");
		QPushButton *Retry = new QPushButton("Retry");
		QPushButton *Quit  = new QPushButton("Exit");

		grid->addWidget(label,0,0,1,2);
		grid->addWidget(Retry,1,0);
		grid->addWidget(Quit,1,1);

		connect(Quit,SIGNAL(clicked()),QApplication::instance(),SLOT(quit()));
		connect(Retry,SIGNAL(clicked()),this,SLOT(Restart()));

		hit->show();

	}
}

void Snake::Restart()
{
	QWidget *sender  =  qobject_cast<QWidget*>(QWidget::sender());

	for(auto block : blocks)
		delete block;

	blocks.clear();

	push(new Block(this));
	push(new Block(this));
	push(new Block(this));

	d = RIGHT;

	delete sender->parentWidget();
	timer->start(speed);
}
