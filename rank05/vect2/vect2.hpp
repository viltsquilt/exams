#pragma once

#include <iostream>

class vect2
{
	private:
			int	_x;
			int	_y;
	public:
			vect2(int x = 0, int y = 0) : _x(x), _y(y) {};
			vect2(const vect2 &orig) : _x(orig._x), _y(orig._y) {};
			vect2&	operator=(const vect2 &other);


}
