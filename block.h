/*
 * File block.h
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#ifndef BLOCK_H
#define BLOCK_H

#include <QFrame>
#include "snake.h"

class Snake::Block : public QFrame
{
	Q_OBJECT
public:
		Block(QWidget*p);
		void ResetStyle();
private:
		QString *style;
};

#endif // BLOCK_H
