/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Background.hpp"

Game::Game() {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	clear();
	refresh();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);

	// win = newwin();

	return ;
}

Game::Game(const Game & src) {

	*this = src;
	
	return ;
}

Game::~Game(void) {

	// delete player;
	// delete stars;
	// delete asteroids;
	endwin();
}

Game &	Game::operator=(Game const & raw) {

	if (this != &raw) {

	// 	main_win = raw.main_win;
	// 	game_win = raw.game_win;
	// 	player = raw.player;
	// 	stars = raw.stars;
	// 	asteroids = raw.asteroids;
	}

	return *this;
}

void	Game::writeInfoTab(int x, int y, time_t z_time, int score, int health) {

	int i = 0;

	while (++i < x - 1) {
		mvprintw(3, i, "-");
	}
	wattron(stdscr, COLOR_PAIR(4));

	mvprintw(1, 2, "Time: %ld", (time(0) - z_time));
	mvprintw(1, 15, "Score: %d", score);
   	mvprintw(1, 30, "Health: %-3d", health);


	wattroff(stdscr, COLOR_PAIR(4));

	y = 0;
}

void 	Game::run() {

	int x;
	int y;
	int xOld;
	int yOld;
	int	t = 0;
	time_t z_time = time(0);
	getmaxyx(stdscr, y, x);
	int score = 0;
	int health = 100;
	bool gameOver = false;
	Boss boss;

	Enemies	enemies[150];
	Background	background[150];
	
	Player * p = new Player(stdscr, y * 0.9, x / 2, L'🚁');

	while (p->getmv() != 'e' && !gameOver) {
		getmaxyx(stdscr, y, x);
		while (x <= 35 || y <= 35) {
			clear();
			mvwprintw(stdscr, 2, 3, "Too small window");
			refresh();
			getmaxyx(stdscr, y, x);
			usleep(10000);
		}
		if (y != yOld || x != xOld) 
		{
			p->setMaxCoords(x, y);
			clear();
		}

		xOld = x;
		yOld = y;
		p->display();
		refresh();
		// p->moveShots();

		if (t % 25 == 0)
			for (int i = 0; i < 3; i++) {
				for (int l = 0; l < 150; l++) {
					if (!enemies[l].pos.exist) {
						enemies[l].create(x);
						enemies[l].pos.exist = true;
						break ;
					}
				}
			}

		if (t % 13 == 0)
			for (int i = 0; i < 150; i++) {
				if (enemies[i].pos.exist) {
					enemies[i].move(y);
					if (enemies[i].pos.exist)
						mvwprintw(stdscr, enemies[i].pos.y, enemies[i].pos.x, "%c", 'V');
					if (p->yLoc == enemies[i].pos.y && p->xLoc == enemies[i].pos.x) {
						health -= 20;
						if (health <= 0) {
							gameOver = true;
						}
						enemies[i].pos.exist = false;
						mvwprintw(stdscr, enemies[i].pos.y, enemies[i].pos.x, "%c", ' ');
						mvwprintw(stdscr, enemies[i].pos.y + 1, enemies[i].pos.x, "%c", ' ');
					}
				}
			}


//------------------------------------------Boss---------------------------------------

		for (int i = 0; i < 9; i++) {
			mvwprintw(stdscr, boss.pos[i].y, boss.pos[i].x, "%c", ' ');
		}
		if (t % 15 == 0) {
			if (boss.pos[0].x > 1 && !boss.yy) {
				for (int i = 0; i < 9; i++)
					boss.pos[i].x -= 1;
				if (boss.pos[0].x <= 2)
					boss.yy = true;
			}
			else {
				boss.yy = true;
				for (int i = 0; i < 9; i++) {
					boss.pos[i].x += 1;
				}
				if (boss.pos[8].x >= x - 3)
					boss.yy = false;
			}
		}
		for (int i = 0; i < 9; i++) {
			mvwprintw(stdscr, boss.pos[i].y, boss.pos[i].x, "%lc", boss.chars[i]);
		}

		// if (y % 30) {
		// 	boss.shoot();

		// if (boss.shots[i].exist) {
		// 	mvwaddch(stdscr, boss.shots[i].y, boss.shots[i].x, ' ');
		// 	boss.shots[i].y++;
		// 	mvwprintw(stdscr, boss.shots[i].y, boss.shots[i].x, "%c", '|');
		// }
		// }
		refresh();

//------------------------------------------Background-----------------------------------
		
		if (t % 5 == 0)
			for (int i = 0; i < 2; i++) {
				for (int l = 0; l < 150; l++) {
					if (!background[l].pos.exist) {
						background[l].create(x);
						background[l].pos.exist = true;
						break ;
					}
				}
			}

		// switch(choice)
		// {
		// 	wchar 
		// 	case '1':
		// 		;
		// 		break;
		// 	case KEY_DOWN:
		// 		mvdown();
		// 		break;
		// 	case KEY_LEFT:
		// 		mvleft();
		// 		break;
		// 	case KEY_RIGHT:
		// 		mvright();
		// 		break;
		// 	default:
		// 		break;
		// }


		if (t % 5 == 0)
			for (int i = 0; i < 150; i++) {
				background[i].move(y);
				if (background[i].pos.exist)
					mvwprintw(stdscr, background[i].pos.y, background[i].pos.x, "%c", '.');
			}
//-----------------------------------------------------------------------------------------

		if (t % 4 == 0)
			for (int i = 0; i < 20; i++) {
				if (p->shots[i].exist) {
					mvwaddch(stdscr, p->shots[i].y, p->shots[i].x, ' ');
					p->shots[i].y--;
					if ((p->shots[i].y - 1) < 4) {
						p->shots[i].exist = false;
						break ;
					}
					// mvwaddch(stdscr, p->shots[i].y, p->shots[i].x, '|');
					mvwprintw(stdscr, p->shots[i].y, p->shots[i].x, "%lc", L'|'); //L'💩'
					for (int l = 0; l < 150; l++) {
						if ((p->shots[i].y == enemies[l].pos.y || p->shots[i].y == enemies[l].pos.y + 1) && p->shots[i].x == enemies[l].pos.x) {
							score += 20;
							enemies[l].pos.exist = false;
							mvwprintw(stdscr, enemies[l].pos.y, enemies[l].pos.x, "%c", ' ');
							mvwprintw(stdscr, enemies[l].pos.y + 1, enemies[l].pos.x, "%c", ' ');
							p->shots[i].exist = false;
							mvwprintw(stdscr, p->shots[i].y, p->shots[i].x, "%c", ' ');
						}
					}
				}
			}
		box(stdscr, 0, 0);
		writeInfoTab(x, y, z_time, score, health);
		// mvprintw(20, 20, "xuy");
		// mvprintw(22, 22, "%i   %i f", x, y);
		t++;
		refresh();
		usleep(10000);
	}

// 🛸🌶🥦🥔🥥🥝🙂🤬🤯 ⏱⏲🕰🛰🧀🌤☄🦑🦐🦀🛫🛬🛩🛸
}
