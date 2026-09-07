#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2 &orig) : x(orig.x), y(orig.y) {}

vect2&	vect2::operator=(const vect2 &orig)
{
	if (this != &orig)
	{
		x = orig.x;
		y = orig.y;
	}
	return (*this);
}

vect2::~vect2() {}

//4 plus
vect2	vect2::operator+(const vect2 &orig) const
{
	return vect2(x + orig.x, y + orig.y);
}

vect2&	vect2::operator+=(const vect2 &orig)
{
	x += orig.x;
	y += orig.y;
	return (*this);
}

vect2&	vect2::operator++()
{
	x += 1;
	y += 1;
	return (*this);
}

vect2	vect2::operator++(int)
{
	vect2	copy = *this;
	++(*this);
	return (copy);
}

//5 minus
vect2	vect2::operator-(const vect2 &orig) const
{
	return vect2(x - orig.x, y - orig.y);
}

vect2&	vect2::operator-=(const vect2 &orig)
{
	x -= orig.x;
	y -= orig.y;
	return (*this);
}

vect2&	vect2::operator--()
{
	x -= 1;
	y -= 1;
	return (*this);
}

vect2	vect2::operator--(int)
{
	vect2	copy = *this;
	--(*this);
	return (copy);
}

vect2	vect2::operator-() const
{
	return vect2(-x, -y);
}

//3 multi
vect2	vect2::operator*(int scalar) const
{
	return vect2(x * scalar, y * scalar);
}

vect2&	vect2::operator*=(int scalar)
{
	x *= scalar;
	y *= scalar;
	return (*this);
}

//2 bool
bool	vect2::operator==(const vect2 &orig) const
{
	return (x == orig.x && y == orig.y);
}

bool	vect2::operator!=(const vect2 &orig) const
{
	return !(*this == orig);
}

//2 index
int&	vect2::operator[](int index)
{
	return (index == 0) ? x : y;
}

const int&	vect2::operator[](int index) const
{
	return (index == 0) ? x : y;
}

//2 getters
int	vect2::getX() const
{
	return (x);
}

int	vect2::getY() const
{
	return (y);
}

//1 iostream

vect2	operator*(int scalar, const vect2 &orig)
{
	return (orig * scalar);
}

std::ostream&	operator<<(std::ostream &os, const vect2 &orig)
{
	os << "{" << orig.getX() << ", " << orig.getY() << "}";
	return (os);
}
