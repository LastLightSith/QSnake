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
#include <thread>

class Fruit;

class Snake:public QWidget
{
	Q_OBJECT


public:
		Snake(QWidget *parent,QSize ParentSize);
		static QSize *BlockSize;
private:
		class Block;
		enum Direction {UP=0,DOWN,LEFT,RIGHT};

		Direction d = RIGHT;
		QTimer *timer =nullptr;
		QSize ParentSize;
		Fruit *fruit =nullptr;
		const int speed = 50;
		std::queue<Direction> Pending;
		std::queue<Block*> PendingBlocks;
		QString *HeadStyle =nullptr;
		QString *HitStyle =nullptr ;
		std::thread *ft =nullptr;
		bool isFruitReady = true;


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
