#pragma	once

#include <iostream>

class vect2
{
	private:
		int	x;
		int	y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &orig);
		vect2&	operator=(const vect2 &orig);
		~vect2();

		//4 plus
		vect2	operator+(const vect2 &orig) const;
		vect2&	operator+=(const vect2 &orig);
		vect2&	operator++();
		vect2	operator++(int);
		//5 minus
		vect2	operator-(const vect2 &orig) const;
		vect2&	operator-=(const vect2 &orig);
		vect2&	operator--();
		vect2	operator--(int);
		vect2	operator-() const;
		//3 multi
		vect2	operator*(int scalar) const;
		vect2&	operator*=(int scalar);
		//2 bool
		bool	operator==(const vect2 &orig) const;
		bool	operator!=(const vect2 &orig) const;
		//2 index
		int&	operator[](int index);
		const int&	operator[](int index) const;
		//2 getters
		int	getX() const;
		int	getY() const;
		//1 iostream
};
		vect2	operator*(int scalar, const vect2 &orig);
		std::ostream&	operator<<(std::ostream &os, const vect2 &orig);
