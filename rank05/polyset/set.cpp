#include "set.hpp"

set::set(searchable_bag &sb) : sb(&sb) {}

set::set(const set &orig) : sb(orig.sb) {}

set& set::operator=(const set &orig)
{
	if (this != &orig)
	{
		sb = orig.sb;
	}
	return (*this);
}

set::~set() {}

void	set::insert(int val)
{
	if (!this->sb->has(val))
		this->sb->insert(val);
}

void	set::insert(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->insert(array[i]);
	}
}

void	set::print() const
{
	this->sb->print();
}

void	set::clear()
{
	this->sb->clear();
}

bool	set::has(int val) const
{
	return (this->sb->has(val));
}

searchable_bag&	set::get_bag() const
{
	return *(this->sb);
}
