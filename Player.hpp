#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#include <iostream>
#include <curses.h>
#include "Game.hpp"
//#include "../inc/General.hpp"

typedef struct  s_shot
{
	int x;
	int y;
	bool exist;
}				t_shot;

class Player
{
public:
	Player(WINDOW * win, int y, int x, wchar_t c);

	void	mvup();
	void	mvdown();
	void	mvleft();
	void	mvright();
	int		getmv();
	void	display();
	void	shoot();
	t_shot  shots[42];
	void	moveShots();
	int		xMax, yMax, xLoc, yLoc;

	void setMaxCoords(int xMax, int yMax);

private:
	// t_shot  me[3];
	wchar_t	character; ////////////////////
	WINDOW * curwin;

	~Player();
	
};

#endif