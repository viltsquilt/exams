
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &orig) : tree_bag(orig) {}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag &orig)
{
	if (this != &orig)
	{
		tree_bag::operator=(orig);
	}
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool	searchable_tree_bag::has(int val) const
{
	node	*current = this->tree;

	while (current)
	{
		if (current->value == val)
			return (true);
		else if (current->value < val)
			current = current->r;
		else if (current->value > val)
			current = current->l;
	}
	return (false);
}
