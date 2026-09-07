#pragma	once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag	*sb;
	public:
		set(searchable_bag &sb);
		set(const set &orig);
		set& operator=(const set &orig);
		~set();
		void	insert(int);
		void	insert(int *, int);
		void	print() const;
		void	clear();
		bool	has(int) const;
		searchable_bag&	get_bag() const;
};
