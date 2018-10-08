#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP
# include <ncurses.h>
# include <locale.h>
# include <string>
# include <unistd.h>

typedef struct  s_coor
{
	int x;
	int y;
	bool exist;
}				t_coor;

class Background {

public:

	Background(void);
	Background(Background const & src);
	~Background(void);

	void	run(void);
	Background &	operator=(Background const & raw);
	t_coor pos;
	void	create(int maxX);
	void	move(int maxY);

private:

	// WINDOW *	win;
};

#endif