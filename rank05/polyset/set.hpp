#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag	*bag;
	public:
		set(const set& orig);
		set& operator=(const set& orig);
		~set();
		set(searchable_bag& s_bag);

		void	insert(int);
		void	insert(int *, int);
		void	print() const;
		void	clear();
		bool	has(int) const;

		searchable_bag&	get_bag() const;
};
