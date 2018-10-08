#include "Player.hpp"
#include "Game.hpp"

Player::Player(WINDOW * win, int y, int x, wchar_t c)
{
	curwin = win;
	// me[0].y = y/2;
	// me[1].y = y/2;
	// me[0].x = x/2;
	// me[1].x = x/2+1;
	// for (int i = 0; i < 3; i++) {
	// 	me[i].x = x + i;
	// 	me[i].y = y;
	// }
	// getmaxyx(curwin, yMax, xMax);
	yMax = y;
	xMax = x;
	yLoc = 20;
	xLoc = 30;
	keypad(curwin, true);
	character = c;
	for (int i = 0; i < 42; i++) {
		shots[i].exist = false;
	}
}

void Player::shoot() {
	for (int i = 0; i < 42; i++) {
		if (!shots[i].exist) {
			shots[i].x = xLoc;
			if ((yLoc - 1) < 4) {
				shots[i].y = 4;
			} else {
				shots[i].y = yLoc - 1;
			}
			shots[i].exist = true;
			// mvwaddch(curwin, shots[i].y, shots[i].x, '|');
			mvwprintw(curwin, shots[i].y, shots[i].x, "%lc", L'🔥');
			// moveShots();
			break ;
		}
	}
}

// void Player::moveShots() {
// 	for (int i = 0; i < 20; i++) {
// 		if (shots[i].exist) {
// 			mvwaddch(curwin, shots[i].y, shots[i].x, ' ');
// 			shots[i].y--;
// 			if ((shots[i].y - 1) < 4) {
// 				shots[i].exist = false;
// 				break ;
// 			}
// 			mvwprintw(curwin, shots[i].y, shots[i].x, "%lc", L'💩');
// 			// mvwprintw(curwin, shots[i].y,shots[i].x, "%lc", L'ツ');
// 		}
// 	}
// } //delete

void Player::mvup()
{

	// for (int i = 0; i < 3; i++) {
	// 	mvwaddch(curwin, me[i].y, me[i].x, ' ');
	// 	me[i].y--;
	// 	if (me[i].y < 4)
	// 		me[i].y = 4;
	// }
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc--;
	if (yLoc < 6)
		yLoc = 6;
}

void Player::mvdown()
{
	// for (int i = 0; i < 2; i++) {
	// 	mvwaddch(curwin, me[i].y, me[i].x, ' ');
	// 	me[i].y++;
	// 	if (me[i].y > yMax-2)
	// 		me[i].y = yMax-2;
	// }
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc++;
	if (yLoc > yMax-2)
		yLoc = yMax-2;
}

void Player::mvleft()
{
	// for (int i = 0; i < 3; i++) {
	// 	mvwaddch(curwin, me[i].y, me[i].x, ' ');
	// 	me[i].x--;
	// 	if (me[i].x < 3)
	// 		me[i].x = 3 + i;
	// }
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc--;
	if (xLoc < 2)
		xLoc = 1;
}

void Player::mvright()
{
	// for (int i = 0; i < 3; i++) {
	// 	mvwaddch(curwin, me[i].y, me[i].x, ' ');
	// 	me[i].x++;
	// 	if (me[i].x > xMax-3)
	// 		me[i].x = xMax-3 - i;
	// }
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc++;
	if (xLoc > xMax - 9)
		xLoc = xMax - 9;
}



int Player::getmv()
{
	int choice = wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		case ' ':
			shoot();
			break;
		default:
			break;
	}
	return choice;
}

void Player::display()
{
	// for (int i = 0; i < 3; i++) {
		// mvwaddch(curwin, me[i].y, me[i].x, character);
		// mvwprintw(curwin, me[i].y, me[i].x, "%c", character);
	// }
	// mvwaddch(curwin, yLoc, xLoc, character);
	mvwprintw(curwin, yLoc, xLoc, "%lc", character);
}

void	Player::setMaxCoords(int xMax, int yMax) {
	this->xMax = xMax;
	this->yMax = yMax;
}
