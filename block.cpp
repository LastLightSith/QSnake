/*
 * File block.cpp
 * created on 30-7-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#include "block.h"
#include <QFrame>

Snake::Block::Block(QWidget *p):
	QFrame(p)
{
	setFixedSize(*BlockSize);
	setStyleSheet
	(
		"QFrame{"
		"background-color: aqua;"
		"border-radius: 5%;"
		"border: 3px solid green;"
		"}"
	);
	show();
}
