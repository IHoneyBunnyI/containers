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
	//public:
		//typedef Iterator														iterator_type;
		//typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		//typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		//typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
		//typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
		//typedef typename ft::iterator_traits<Iterator>::reference				reference;
	public:
		typedef Iterator														iterator_type;
		typedef typename Iterator::iterator_category							iterator_category;
		typedef typename Iterator::value_type									value_type;
		typedef typename Iterator::difference_type								difference_type;
		typedef typename Iterator::pointer										pointer;
		typedef typename Iterator::reference									reference;
	private:
		iterator_type it;

	public:
		reverse_iterator(); 
		explicit reverse_iterator (iterator_type it);

		reverse_iterator(const reverse_iterator<Iterator>& rev_it);

		reverse_iterator& operator=( const reverse_iterator<Iterator>& other );

		iterator_type base();
};

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator()
{
	this->it = 0;
}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator (iterator_type it)
{
	this->it = it;
}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iterator>& ref)
{
	this->it = ref;
}


template <class Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator = (const reverse_iterator<Iterator>& other)
{
	if (*this != other)
		this->it = other.base();
	return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type ft::reverse_iterator<Iterator>::base()
{
	return this->it;
}

}


#endif
