#ifndef RED_BLACK_TREE_CONST_ITERATOR
#define RED_BLACK_TREE_CONST_ITERATOR

#include <iostream>
#include "RedBlackTreeIterator.hpp"

namespace ft
{

template <class T>
class RedBlackTreeConstIterator
{
public:
	typedef T										value_type;
	typedef const T&								reference;
	typedef const T									pointer;
	typedef RedBlackTreeIterator<value_type>		iterator;
	typedef std::bidirectional_iterator_tag 		iterator_category;
	typedef std::ptrdiff_t							difference_type;
	typedef RedBlackTreeConstIterator<value_type>	self;
	typedef const RedBlackTreeNode<value_type>*		link_type;

	//Constructors
	RedBlackTreeConstIterator();
	explicit	RedBlackTreeConstIterator(link_type x);
	RedBlackTreeConstIterator(const iterator& x);

	const RedBlackTreeNode<value_type>* node;

	//Operators
	reference	operator*() const;
	pointer		operator->() const;
	self&		operator++();
	self		operator++(int);
	self&		operator--();
	self		operator--(int);
	bool		operator==(const self& ref) const;
	bool		operator!=(const self& ref) const;
};

template <class T>
RedBlackTreeConstIterator<T>::RedBlackTreeConstIterator(): node() {};

template <class T>
RedBlackTreeConstIterator<T>::RedBlackTreeConstIterator(link_type x): node(x) {};

template <class T>
RedBlackTreeConstIterator<T>::RedBlackTreeConstIterator(const iterator& x) : node(x.node) {};

template <class T>
typename RedBlackTreeConstIterator<T>::reference RedBlackTreeConstIterator<T>::operator*() const
{
	return this->node->val;
}

template <class T>
typename RedBlackTreeConstIterator<T>::pointer RedBlackTreeConstIterator<T>::operator->() const
{
	return &(this->node->val);
}

template <class T>
typename RedBlackTreeConstIterator<T>::self& RedBlackTreeConstIterator<T>::operator++()
{
	this->node = redBlackTree_increment(this->node);
	return (*this);
}

template <class T>
typename RedBlackTreeConstIterator<T>::self RedBlackTreeConstIterator<T>::operator++(int)
{
	self tmp = *this;
	this->node = redBlackTree_increment(this->node);
	return tmp;
}

template <class T>
typename RedBlackTreeConstIterator<T>::self& RedBlackTreeConstIterator<T>::operator--()
{
	this->node = redBlackTree_decrement(this->node);
	return (*this);
}

template <class T>
typename RedBlackTreeConstIterator<T>::self RedBlackTreeConstIterator<T>::operator--(int)
{
	self tmp = *this;
	this->node = redBlackTree_decrement(this->node);
	return tmp;
}

template <class T>
bool ft::RedBlackTreeConstIterator<T>::operator==(const self& ref) const
{
	return this->node == ref.node;
}

template <class T>
bool ft::RedBlackTreeConstIterator<T>::operator!=(const self& ref) const
{
	return this->node != ref.node;
}

}


#endif
