#include "Ship.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

Ship::Ship( void ) {
	return ;
}

Ship::Ship( WINDOW * win, int y, int x, char c ) : _win(win), _yLoc(y), _xLoc(x), _char(c) {
	return ;
}

Ship::Ship( Ship const & src ) {
	*this = src;
	return ;
}

Ship & Ship::operator=( Ship const & rhs ) {
	this->_win = rhs._win;
	this->_yLoc = rhs._yLoc;
	this->_xLoc = rhs._xLoc;
	this->_char = rhs._char;
	return (*this);
	// TODO: add more copying of fields from the partent class, if needed
}

Ship::~Ship( void ) {
	return ;
}


void Ship::mvUp( void ) {
	if (this->_yLoc > Y_MIN) {
		this->displaySpace();
		(this->_yLoc)--;
	}
}

void Ship::mvDown( void ) {
	if (this->_yLoc < Y_MAX - 1) {
		this->displaySpace();
		(this->_yLoc)++;
	}
}

void Ship::mvLeft( void ) {
	if (this->_xLoc > X_MIN) {
		this->displaySpace();
		(this->_xLoc)--;
	}
}

void Ship::mvRight( void ) {
	if (this->_xLoc < X_MAX - 1) {
		this->displaySpace();
		(this->_xLoc)++;
	}
}

int Ship::getMv( void ) {
	int input = wgetch(this->_win);

	switch (input) {
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN:
			mvDown();
			break;
		case KEY_LEFT:
			mvLeft();
			break;
		case KEY_RIGHT:
			mvRight();
			break;
		default:
			break;
		// case KEY_BREAK: // add shooting
			// shot()
	}
	return (input);
}

void Ship::display( void ) const {
	mvwaddch(this->_win, this->_yLoc, this->_xLoc, this->_char);
}

void Ship::displaySpace( void ) const {
	mvwaddch(this->_win, this->_yLoc, this->_xLoc, ' ');
}
