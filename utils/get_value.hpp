#ifndef GET_VALUE_HPP
#define GET_VALUE_HPP

template <class value>
struct get_value
{
	value& operator() (value& v)
	{
		return v;
	}

	const value& operator() (const value& v) const
	{
		return v;
	}
};


#endif
