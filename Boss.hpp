#ifndef BOSS_HPP
# define BOSS_HPP
# include <ncurses.h>
# include <locale.h>
# include <string>
# include <unistd.h>
# include "Enemies.hpp"

class Boss {

public:

	Boss(void);
	Boss(Boss const & src);
	~Boss(void);

	Boss &	operator=(Boss const & raw);
	t_coords pos[9];
	wchar_t	chars[9];
	t_coords shots[30];
	bool yy;
	void shoot();

private:
};

#endif