#include <iostream>
#include <ncurses.h>

int	main() {
	int x = 0;
	int y = 0;

	initscr();
	cbreak();
	// curs_set(0);
	WINDOW * win = newwin(10, 15, 0, 0);
	keypad(win, true);
	while (true)
	{
		x++;
		// move(y, x);
		mvaddch(y, x, 'k');
		wrefresh(win);
		nodelay(win, true);
		timeout(20);
	}
	endwin();
	return (0);
}