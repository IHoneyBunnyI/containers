#ifndef SET_HPP
#define SET_HPP
#include <iostream>
#include "RedBlackTree.hpp"
#include "get_value.hpp"

namespace ft
{

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{
	public:
		typedef T key_type;
		typedef T value_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef Alloc allocator_type;
	 private:
		typedef typename ft::RedBlackTree<key_type, value_type, identity<value_type>, key_compare, allocator_type> tree_type;
		tree_type tree;
};

}
#endif
