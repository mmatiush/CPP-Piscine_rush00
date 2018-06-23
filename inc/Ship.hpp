#ifndef SHIP_HPP
# define SHIP_HPP
# include <iostream>
# include <unistd.h>
# include <ncurses.h>
# define WIN_X_MIN 0
# define WIN_Y_MIN 0
# define WIN_X_SIZE 60
# define WIN_Y_SIZE 20
// WIN_MIN - 1
# define X_MIN 1
# define Y_MIN 1
// WIN_SIZE - 1
# define X_MAX 59
# define Y_MAX 19

class Ship {

public:
	Ship( void );
	Ship( Ship const & src );
	Ship (WINDOW * win, int y, int x, char c);
	Ship & operator=( Ship const & rhs ); // TODO:
	~Ship( void );
	void mvUp( void );
	void mvDown( void );
	void mvLeft( void );
	void mvRight( void );
	// void shot( void ); // will create a bullet (rocket)
	int	getMv( void );
	void display( void ) const ;
	void displaySpace( void ) const ;

private:
	WINDOW * _win;
	int _yLoc, _xLoc;
	char _char;
};

#endif
