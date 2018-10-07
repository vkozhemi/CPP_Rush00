#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../inc/Player.hpp"
#include "../inc/Enemy.hpp"

int main(int argc, char const *argv[])
{
	srand(time(NULL));
 	time_t z_time = time(0);
	
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	if(!has_colors()){
		endwin();
		exit(1);
 	}

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);

	WINDOW * playwin = newwin(80, 120, 5, 5);
	WINDOW * score = newwin(20, 32, 6, 130);
	wtimeout(playwin,0);

	box(playwin, 0, 0);
	box(score, 0, 0);
	curs_set(0);
	refresh();
	wrefresh(playwin);
	wrefresh(score);


//---------------Usage------------------------------
	wattron(score, COLOR_PAIR(4));
	mvwprintw(score, 7, 2, "Usage: ");
	mvwprintw(score, 9, 4, "Up - ^");
	mvwprintw(score, 10, 4, "Dw - v");
	mvwprintw(score, 11, 4, "L - <");
	mvwprintw(score, 12, 4, "R - >");
	mvwprintw(score, 13, 4, "Shoot - Space");
	mvwprintw(score, 14, 4, "Exit - e");
	wattroff(score,COLOR_PAIR(4));
//----------------------------------------------------


	Player * p = new Player(playwin, 70, 60, '^');


	wattron(score, COLOR_PAIR(4));
	Enemy * e = new Enemy(playwin, 10, 60, 'V');
	wattroff(score,COLOR_PAIR(4));

	int cycle = 0;
	do {
		clear();
		if (cycle % 1000 == 0) {
			e->getmv();
		}
		

		e->display();

		p->display();
		wattron(score, COLOR_PAIR(4));
		mvwprintw(score, 1, 2, "Time: %ld", (time(0) - z_time));
		mvwprintw(score ,3, 2, "Score: %d", 0);
		//mvwprintw(score ,3, 2, "Score: %d", pole.p.getScore());
   		mvwprintw(score ,5, 2, "Health: %-3d", 0);
   		//mvwprintw(score ,6, 2, "Health: %-3d", pole.p.getHealth());
		wattroff(score,COLOR_PAIR(4));
		wrefresh(playwin);
		wrefresh(score);
		start_color();
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		cycle++;


	} while (p->getmv() != 'e');

	endwin();

	return 0;
}