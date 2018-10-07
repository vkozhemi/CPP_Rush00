#include "../inc/Enemy.hpp"

Enemy::Enemy(WINDOW * win, int y, int x, char c)
{
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
}

void Enemy::mvdown()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
		yLoc++;
	if (yLoc > yMax-2) {
		yLoc = 3;
		xLoc += 10;
		if (xLoc > 110)
			xLoc = 10;
	}
}


int Enemy::getmv()
{
	int choice = wgetch(curwin);
	mvdown();
	return choice;
}

void Enemy::display()
{
	mvwaddch(curwin, yLoc, xLoc, character);
}
