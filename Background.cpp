#include "Background.hpp"

Background::Background() {
	pos.exist = false;
	pos.x = 0;
	pos.y = 0;
	return ;
}

Background::Background(const Background & src) {

	*this = src;
	
	return ;
}

Background::~Background(void) {

}

Background &	Background::operator=(Background const & raw) {

	if (this != &raw) {
	}

	return *this;
}

void	Background::create(int maxX) {
	pos.x = rand() % maxX;
	pos.y = 5;
	pos.exist = true;
}

void	Background::move(int maxY) {
	mvwprintw(stdscr, this->pos.y, this->pos.x, "%c", ' ');
	this->pos.y++;
	if (this->pos.y >= maxY - 2) {
		this->pos.exist = false;
		mvwprintw(stdscr, this->pos.y, this->pos.x, "%c", ' ');
	}
}
