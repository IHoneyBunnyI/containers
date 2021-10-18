#ifndef PAIR_FIRST_HPP
#define PAIR_FIRST_HPP

template <class Pair>
struct pair_first
{
	typename Pair::first_type& operator()(Pair& p)
	{
		return p.first;
	}

	const typename Pair::first_type& operator()(const Pair& p) const
	{
		return p.first;
	}
};

#endif
