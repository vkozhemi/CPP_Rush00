#include "rush.hpp"
#include <time.h>

int main(void)
{
 int action;
 int count = 0;

 srand(time(NULL));
 time_t zero_time = time(0);

 initscr();
 noecho();
 cbreak();
 curs_set(0);


 if(!has_colors()){
  endwin();
  exit(1);
 }

 start_color();
 init_pair(1, COLOR_WHITE, COLOR_BLACK);
 init_pair(2, COLOR_RED, COLOR_BLACK);
 init_pair(3, COLOR_YELLOW, COLOR_BLACK);
 init_pair(4, COLOR_GREEN, COLOR_BLACK);
 
 action = 0;
 WINDOW *win = newwin(HGHT, WDTH, 0, 0);
 WINDOW *score = newwin(WDTH / 7, HGHT / 3 + 20, 0 , WDTH);
 wtimeout(win,0);
 keypad(win, true);

 box(win, 0, 0);
 box(score, 0,0);

 //refresh();
 GameField pole; // in constructor create empty map & generate enemies & put player on it & initialize cycle to 0
 //int sec = 0;

 //wtimeout(win,0);
 keypad(win, true);
 curs_set(0);
 while (action != 'x')
 {
  count++;
  wattron(score, COLOR_PAIR(3));
   mvwprintw(score ,6, 2, "Time: %ld", (time(0) - zero_time));
   mvwprintw(score ,3, 2, "Score: %d", pole.p.getScore());
   mvwprintw(score ,9, 2, "Health: %-3d", pole.p.getHealth());
  wattroff(score,COLOR_PAIR(3));
  pole.movePlayer();
  if (pole.getCycle() % 400 == 0)
  {
   pole.moveBullets();
   if (pole.getCycle() % 3000 == 0)
    pole.moveEnemies();
  }
  pole.p.check(pole.getField());
  if (action == KEY_UP)
  {
   pole.setSymb(pole.p.getY(), pole.p.getX(), ' ');
   pole.p.up();
   pole.p.check(pole.getField());
   pole.movePlayer();
  }
  else if (action == KEY_DOWN)
  {
   pole.setSymb(pole.p.getY(), pole.p.getX(), ' ');
   pole.p.down();
   pole.p.check(pole.getField());
   pole.movePlayer();
  }
  else if (action == KEY_LEFT)
  {
   pole.setSymb(pole.p.getY(), pole.p.getX(), ' ');
   pole.p.left();
   pole.p.check(pole.getField());
   pole.movePlayer();
  }
  else if (action == KEY_RIGHT)
  {
   pole.setSymb(pole.p.getY(), pole.p.getX(), ' ');
   pole.p.right();
   pole.p.check(pole.getField());
   pole.movePlayer();
  }
  else if (action == ' ')
  {
   pole.addBullet(pole.p.createShoot());
  }

  else if (action == 'c')
  {
   pole.addBullet(pole.p.createShoot());
  }
  else if (action == 27)
   break;

  box(win,0,0);
  int strs = 0;
  while(++strs < HGHT - 3)
  {
   int y = 1;
   while (y < WDTH - 3)
   {
    char ch =  pole.getField()[strs].c_str()[y++];
    if (ch == ENEMY)
    {
     wattron(win, COLOR_PAIR(2));
     mvwaddch(win, strs, y , ch);
     wattroff(win, COLOR_PAIR(2));
    }
    else
      mvwaddch(win, strs, y , ch);
   }

  }
  pole.setCycle(1);
  pole.checkShoots();
  wrefresh(win);
  wrefresh(score);
  action = wgetch(win);
  if (!pole.getGameStatus())
  {
   wattron(score, COLOR_PAIR(3));
   mvwprintw(score ,9, 2, "Health: %-3d", pole.p.getHealth());
   wattroff(score,COLOR_PAIR(3));
   wrefresh(score);
   action = 'p';
   break;
  }
 }
 if (action == 'p')
 { wattron(win, COLOR_PAIR(3));
  while ((action = wgetch(win)) != 'q')
  {
   mvwprintw(win, HGHT / 2, WDTH / 2 - 7, "GAME OVER!!!");
   mvwprintw(win, HGHT / 2 + 1, WDTH / 2 - 9, "press Q to quit");
  }
 }
 clear();
 endwin();
 return (0);
}