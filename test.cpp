#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Ship.hpp"

int	main() {
	initscr();
	cbreak();
	curs_set(0);

	WINDOW * win = newwin(WIN_Y_SIZE, WIN_X_SIZE, 0, 0);
	Ship player(win, WIN_Y_SIZE / 2, X_MIN + 3, '>');
	wrefresh(win);
	while (true)
	{
		box(win, 0, 0);
		if (player.getMv() == 'q')
			break ;
		player.display();
		wrefresh(win);
		// usleep(5000);
	}
	endwin();
	std::cout << "Your score is: " << std::endl; 
	return (0);
}
