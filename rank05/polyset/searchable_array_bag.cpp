#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &orig) : array_bag(orig) {}

searchable_array_bag&	searchable_array_bag::operator=(const searchable_array_bag &orig)
{
	if (this != &orig)
	{
		array_bag::operator=(orig);
	}
	return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool	searchable_array_bag::has(int val) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == val)
			return (true);
	}
	return (false);
}
