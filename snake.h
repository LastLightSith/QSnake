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
#include <vector>
#include <QWidget>
#include <QSize>

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

		void push(Block *b ,Direction pd=LEFT);
		void CheckHead();

protected:
		void keyPressEvent(QKeyEvent *event);

private slots:
		void Crawl();
		void Restart();
		const int speed = 60;
public:
		std::vector<Block*> blocks;
		void setFruit(Fruit *fruit);

signals:
		void Eaten();
};

#endif // SNAKE_H
