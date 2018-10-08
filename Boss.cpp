#include "Boss.hpp"

Boss::Boss() {
	this->yy = false;
	this->chars[0] = L'¯';
	this->chars[1] = '\\';
	this->chars[2] = '_';
	this->chars[3] = '(';
	this->chars[4] = L'ツ';
	this->chars[5] = ')';
	this->chars[6] = '_';
	this->chars[7] = '/';
	this->chars[8] = L'¯';

	for (int i = 0; i < 9; i++) {
		this->pos[i].x = i + 5;
		this->pos[i].y = 4;
	}

	for (int i = 0; i < 20; i++) {
		shots[i].exist = false;
	}
	return ;
}

void Boss::shoot() {
	for (int i = 0; i < 20; i++) {
		if (!shots[i].exist) {
			shots[i].x = pos[4].x;
			shots[i].y = pos[4].y + 1;
			shots[i].exist = true;
			// mvwaddch(curwin, shots[i].y, shots[i].x, '|');
			mvwprintw(stdscr, shots[i].y, shots[i].x, "%c", '|');
			// moveShots();
			break ;
		}
	}
}

Boss::Boss(const Boss & src) {

	*this = src;
	
	return ;
}

Boss::~Boss(void) {

}

Boss &	Boss::operator=(Boss const & raw) {

	if (this != &raw) {
	}

	return *this;
}
