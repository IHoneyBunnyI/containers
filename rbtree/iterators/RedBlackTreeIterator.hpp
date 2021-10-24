#ifndef RED_BLACK_TREE_ITERATOR
#define RED_BLACK_TREE_ITERATOR
#include <iostream>
#include "../../utils/RedBlackTreeNode.hpp"

namespace ft
{

template <class T>
class RedBlackTreeIterator
{

public:
	typedef T									value_type;
	typedef T&									reference;
	typedef T*									pointer;
	typedef std::bidirectional_iterator_tag 	iterator_category;
	typedef std::ptrdiff_t						difference_type;
	typedef RedBlackTreeIterator<value_type>	self;
	typedef RedBlackTreeNode<value_type>* 		link_type;

	RedBlackTreeNode<value_type>* node;

	//Constructors
	RedBlackTreeIterator();
	explicit	RedBlackTreeIterator(link_type x);

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
RedBlackTreeIterator<T>::RedBlackTreeIterator(): node() {};


template <class T>
RedBlackTreeIterator<T>::RedBlackTreeIterator(link_type x): node(x) {};

template <class T>
typename RedBlackTreeIterator<T>::reference RedBlackTreeIterator<T>::operator*() const
{
	return this->node->val;
}

template <class T>
typename RedBlackTreeIterator<T>::pointer RedBlackTreeIterator<T>::operator->() const
{
	return &(this->node->val);
}

template <class T>
typename RedBlackTreeIterator<T>::self& RedBlackTreeIterator<T>::operator++()
{
	this->node = redBlackTree_increment(this->node);
	return (*this);
}

template <class T>
typename RedBlackTreeIterator<T>::self RedBlackTreeIterator<T>::operator++(int)
{
	self tmp = *this;
	this->node = redBlackTree_increment(this->node);
	return tmp;
}

template <class T>
typename RedBlackTreeIterator<T>::self& RedBlackTreeIterator<T>::operator--()
{
	this->node = redBlackTree_decrement(this->node);
	return (*this);
}

template <class T>
typename RedBlackTreeIterator<T>::self RedBlackTreeIterator<T>::operator--(int)
{
	self tmp = *this;
	this->node = redBlackTree_decrement(this->node);
	return tmp;
}

template <class T>
bool ft::RedBlackTreeIterator<T>::operator==(const self& ref) const
{
	return this->node == ref.node;
}

template <class T>
bool ft::RedBlackTreeIterator<T>::operator!=(const self& ref) const
{
	return this->node != ref.node;
}

}
#endif
