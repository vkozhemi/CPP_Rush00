# newRetroGame
Battlestar Galactica

The goal of this project is to implement a simplistic shoot-em-up-style game in your terminal. For those of you who don’t know what that kind of game is (shame on you, by the way), have a look at Gradius, R-Type, etc...
You will use a ’screen’ made up of a grid of ’squares’, that you can equate to the characters on your terminal, so that the entities of your game are each represented by a character on screen.

![Image alt](https://github.com/vkozhemi/CPP_Rush00/raw/master/img/1.png)

Here are the basic requirements :
	- Single-player
	- Display using the ncurses library
	- Horizontal or vertical scrolling (The screen area moves through the world, very much like in R-Type for example)
	- Random enemies
	- The player can shoot at enemies
	- Basic collision handling (If an enemy touches you, you die)
	- Game entities occupy one ’square’ of the map only.
	- Frame-based timing
	- Displaying score, time, number of lives, etc... on screen

## Installation

`git clone https://github.com/vkozhemi/CPP_Rush00.git`
`cd CPP_Rush00`
`make`

## Run

Standard mode : 

`./ft_retro`


![Image alt](https://github.com/vkozhemi/CPP_Rush00/raw/master/img/2.gif)
