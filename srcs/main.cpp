#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../inc/Player.hpp"

int main(int argc, char const *argv[])
{
	
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);


	WINDOW * playwin = newwin(80, 120, 5, 5);
	box(playwin, 0, 0);
	curs_set(0);
	refresh();
	wrefresh(playwin);

	
	Player * p = new Player(playwin, 70, 60, '^');
	do {
		p->display();
		wrefresh(playwin);

	} while (p->getmv() != 'e');

	endwin();

	return 0;
}