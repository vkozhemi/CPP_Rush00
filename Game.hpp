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

#ifndef GAME_HPP
# define GAME_HPP
# include <ncurses.h>
# include <locale.h>
# include <string>
# include <unistd.h>
# include "Player.hpp"
# include "Enemies.hpp"
# include "Boss.hpp"

typedef struct  s_crds
{
	int x;
	int y;
}				t_crds;

class Game {

public:

	Game(void);
	Game(Game const & src);
	~Game(void);

	void	run(void);
	Game &	operator=(Game const & raw);
	void	writeInfoTab(int x, int y, time_t z_time, int score, int health);

private:

	// WINDOW *	win;
};

#endif