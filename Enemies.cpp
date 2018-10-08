#include "Enemies.hpp"

Enemies::Enemies() {
	pos.exist = false;
	pos.x = 0;
	pos.y = 0;
	return ;
}

Enemies::Enemies(const Enemies & src) {

	*this = src;
	
	return ;
}

Enemies::~Enemies(void) {

}

Enemies &	Enemies::operator=(Enemies const & raw) {

	if (this != &raw) {
	}

	return *this;
}

void	Enemies::create(int maxX) {
	pos.x = rand() % maxX;
	pos.y = 5;
	pos.exist = true;
}

void	Enemies::move(int maxY) {
	mvwprintw(stdscr, this->pos.y, this->pos.x, "%c", ' ');
	this->pos.y++;
	if (this->pos.y >= maxY - 2) {
		this->pos.exist = false;
		mvwprintw(stdscr, this->pos.y, this->pos.x, "%c", ' ');
	}
}
