#ifndef ENEMIES_HPP
# define ENEMIES_HPP
# include <ncurses.h>
# include <locale.h>
# include <string>
# include <unistd.h>

typedef struct  s_coords
{
	int x;
	int y;
	bool exist;
}				t_coords;

class Enemies {

public:

	Enemies(void);
	Enemies(Enemies const & src);
	~Enemies(void);

	Enemies &	operator=(Enemies const & raw);
	t_coords pos;
	void	create(int maxX);
	void	move(int maxY);

private:

};

#endif