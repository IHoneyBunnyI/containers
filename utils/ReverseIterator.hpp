#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"
#include "iterator_traits.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator
{
protected:
	Iterator it;
public:
	typedef Iterator												iterator_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::reference		reference;
	typedef typename ft::iterator_traits<Iterator>::pointer			pointer;

	reverse_iterator();
	explicit reverse_iterator(Iterator x);

	template <class Up>
	reverse_iterator(const reverse_iterator<Up>& ref);

	template <class Up>
	reverse_iterator& operator=(const reverse_iterator<Up>& ref);

	Iterator base() const;
	reference operator*() const;
	pointer  operator->() const;
	reverse_iterator& operator++();
	reverse_iterator  operator++(int);
	reverse_iterator& operator--();
	reverse_iterator  operator--(int);
	reverse_iterator  operator + (difference_type n) const;
	reverse_iterator& operator += (difference_type n);
	reverse_iterator  operator - (difference_type n) const;
	reverse_iterator& operator -= (difference_type n);
	reference operator[](difference_type n) const;
};

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator() : it() {}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator x) : it(x) {}

template <class Iterator>
template <class Up>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Up>& ref) : it(ref.base()) {}

template <class Iterator>
template <class Up>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator=(const reverse_iterator<Up>& ref)
{
	it = ref.base();
	return *this;
}

template <class Iterator>
Iterator ft::reverse_iterator<Iterator>::base() const
{
	return it;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*() const
{
	Iterator itmp = it;
	return *--itmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer  ft::reverse_iterator<Iterator>::operator->() const
{
	//return &(*(--it)); //////////////////AAAAAAAAAAAAAAAAAA
	return &(operator*());
}

template <class Iterator>
reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator ++ ()
{
	--it;
	return *this;
}

template <class Iterator>
reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator ++ (int)
{
	reverse_iterator itmp(*this);
	--it;
	return itmp;
}

template <class Iterator>
reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator -- ()
{
	++it;
	return *this;
}

template <class Iterator>
reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator -- (int)
{
	reverse_iterator itmp(*this);
	++it;
	return itmp;
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator + (difference_type n) const
{
	return reverse_iterator(it - n);
}

template <class Iterator>
reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator+=(difference_type n)
{
	it -= n;
	return *this;
}

template <class Iterator>
reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator - (difference_type n) const
{
	return reverse_iterator(it + n);
}

template <class Iterator>
reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator -= (difference_type n)
{
	it += n;
	return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[](difference_type n) const {return *(*this + n);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Iterator1, class Iterator2>
bool
operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool
operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool
operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool
operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool
operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() <= y.base();
}

template <class Iterator1, class Iterator2>
bool
operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
	return x.base() >= y.base();
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
{
    return y.base() - x.base();
}

template <class _Iter>
reverse_iterator<_Iter> operator+(typename reverse_iterator<_Iter>::difference_type n, const reverse_iterator<_Iter>& x)
{
    return reverse_iterator<_Iter>(x.base() - n);
}

}

#endif
