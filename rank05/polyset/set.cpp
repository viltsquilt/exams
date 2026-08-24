#include "set.hpp"

set::set(searchable_bag &s_bag) : bag(&s_bag){}

set::set(const set& orig) : bag(orig.bag){}

set&	set::operator=(const set& orig)
{
	if (this != &orig)
	{
		this->bag = orig.bag;
	}
	return (*this);
}

set::~set(){}

void	set::insert(int val)
{
	if (!this->has(val))
		this->bag->insert(val);
}

void	set::insert(int *numbers, int size)
{
	for (int i = 0; i < size; i++)
	{
			this->insert(numbers[i]);
	}
}

void	set::print() const
{
	this->bag->print();
}

void	set::clear() 
{
	this->bag->clear();
}

bool	set::has(int val) const
{
	return(this->bag->has(val));
}

searchable_bag&	set::get_bag() const
{
	return *(this->bag);
}
