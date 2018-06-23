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
	unsigned long score = 0;

	WINDOW * header = newwin(3, WIN_X_SIZE, 0, 0);
	WINDOW * win = newwin(WIN_Y_SIZE, WIN_X_SIZE, 2, 0);
	Ship player(win, WIN_Y_SIZE / 2, X_MIN + 3, '>');
	wrefresh(win);
	wrefresh(header);
	keypad(win, true);
	while (true)
	{
		mvwprintw(header, 1, 1, "%s %d", "Score:", score);
		box(win, 0, 0);
		nodelay(win, TRUE);
		if (player.getMv() == 'q')
			break ;
		player.display();
		wrefresh(win);
		wrefresh(header);
		usleep(50000);
		score++;
	}
	endwin();
	std::cout << "Your score is: " << score << std::endl; 
}

int		main(void) {
	ft_retro();
	// system ("leaks --quiet ft_retro");
	return (0);
}