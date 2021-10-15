#ifndef RED_BLACK_TREE_ITERATOR
#define RED_BLACK_TREE_ITERATOR
#include <iostream>
#include "../RedBlackTreeNode.hpp"

namespace ft
{

template <class T>
class RedBlackTreeIterator
{

public:
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;
	typedef RedBlackTreeIterator<value_type> self;
	typedef RedBlackTreeNode<value_type>* link_type;

	RedBlackTreeNode<value_type>* node;

	//Constructors
	RedBlackTreeIterator();
	explicit RedBlackTreeIterator(link_type x);

	//Operators
	reference operator*() const;
	pointer operator->() const;
	self& operator++();
	self operator++(int);
};

}

template <class T>
ft::RedBlackTreeIterator<T>::RedBlackTreeIterator(): node() {};


template <class T>
ft::RedBlackTreeIterator<T>::RedBlackTreeIterator(link_type x): node(x) {};

template <class T>
typename ft::RedBlackTreeIterator<T>::reference ft::RedBlackTreeIterator<T>::operator*() const
{
	return this->node->val;
}

template <class T>
typename ft::RedBlackTreeIterator<T>::pointer ft::RedBlackTreeIterator<T>::operator->() const
{
	return &(this->node->val);
}

template <class T>
typename ft::RedBlackTreeIterator<T>::self& ft::RedBlackTreeIterator<T>::operator++()
{
	this->node = redBlackTree_increment(this->node);
	return (*this);
}

template <class T>
typename ft::RedBlackTreeIterator<T>::self ft::RedBlackTreeIterator<T>::operator++(int)
{
	self tmp = *this;
	this->node = redBlackTree_increment(this->node);
	return tmp;
}



#endif
