#ifndef ENEMY_H
#define ENEMY_H
#include <ncurses.h>
#include <iostream>
#include <curses.h>
//#include "../inc/General.hpp"

class Enemy
{
public:
	Enemy(WINDOW * win, int y, int x, char c);

	//void	mvup();
	void	mvdown();
	// void	mvleft();
	// void	mvright();
	int		getmv();
	void	display();

private:
	int		xLoc, yLoc, xMax, yMax;
	char	character; ////////////////////
	WINDOW * curwin;

	~Enemy();
	
};

#endif