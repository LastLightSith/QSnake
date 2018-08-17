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
	style = new  QString
	(
		"QFrame{"
		"background-color: yellow;"
		"border-radius: 7%;"
		"border: 3px solid green;"
		"}"
	);

	setStyleSheet(*style);
	show();
}

void Snake::Block::ResetStyle()
{
	setStyleSheet(*style);
}
