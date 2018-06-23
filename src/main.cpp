#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Ship.hpp"

void ft_retro() {
	initscr();
	cbreak();
	curs_set(0);
	curs_set(0);
	noecho();

	WINDOW * win = newwin(WIN_Y_SIZE, WIN_X_SIZE, 0, 0);
	Ship player(win, WIN_Y_SIZE / 2, X_MIN + 3, '>');
	wrefresh(win);
	keypad(win, true);
	while (true)
	{
		box(win, 0, 0);
		if (player.getMv() == 'q')
			break ;
		player.display();
		wrefresh(win);
		usleep(5000);
	}
	endwin();
	std::cout << "Your score is: " << std::endl; 
}

int		main(void) {
	ft_retro();
	// system ("leaks --quiet ft_retro");
	return (0);
}