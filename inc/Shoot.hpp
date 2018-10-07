#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#include <iostream>
#include <curses.h>

class Shoot
{
public:
	Shoot(WINDOW * win, int y, int x);

	void	mvup();
	void	display();
  int   getX();
  int   getY();

private:
	int		xLoc, yLoc;
	char	character;
	WINDOW * curwin;

	~Shoot();

};

#endif
