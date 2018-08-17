/*
 * File snake.h
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */

#ifndef SNAKE_H
#define SNAKE_H

#include <QTimer>
#include <QWidget>
#include <QSize>

#include <list>
#include <queue>

class Fruit;

class Snake:public QWidget
{
	Q_OBJECT


public:
		Snake(QWidget *parent,QSize ParentSize);
		static QSize *BlockSize;
private:
		class Block;
		enum Direction
		{UP=0,DOWN,LEFT,RIGHT};


		Direction d = RIGHT;
		QTimer *timer;
		QSize ParentSize;
		Fruit *fruit;
		const int speed = 50;
		std::queue<Direction> Pending;
		QString *HeadStyle;
		QString *HitStyle;


		void push(Block *b ,Direction pd=LEFT);
		void CheckHead();
		void Pause();

protected:
		void keyPressEvent(QKeyEvent *event);

private slots:
		void Crawl();
		void Restart();
public:
		std::list<Block*> blocks;
		void setFruit(Fruit *fruit);
		void Eaten();
};

#endif // SNAKE_H
