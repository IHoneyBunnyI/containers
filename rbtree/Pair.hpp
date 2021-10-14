#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template<class T1, class T2>
struct pair
{
	typedef T1  first_type;
	typedef T2  second_type;

	first_type first;
	second_type second;

	//Constructors
	pair();
	pair(const T1& x, const T2& y);
	template<class U1, class U2>
	pair(const pair<U1, U2>& p);

	//Overloads
	pair& operator=(pair const& p);
};


template<class T1, class T2>
ft::pair<T1, T2>::pair() : first(), second() {}


template<class T1, class T2>
ft::pair<T1, T2>::pair(const T1& x, const T2& y) : first(x), second(y) {}

template<class T1, class T2>
template<class U1, class U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

template<class T1, class T2>
ft::pair<T1, T2>& ft::pair<T1, T2>::operator=(pair const& p)
{
	first = p.first;
	second = p.second;
	return *this;
}


template <class T1, class T2>
bool
operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return x.first == y.first && x.second == y.second;
}

template <class T1, class T2>
bool
operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return !(x == y);
}

template <class T1, class T2>
bool
operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <class T1, class T2>
bool
operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return y < x;
}

template <class T1, class T2>
bool
operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return !(x < y);
}

template <class T1, class T2>
bool
operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
{
    return !(y < x);
}

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
    return pair<T1, T2>(x, y);
}

}
#endif
