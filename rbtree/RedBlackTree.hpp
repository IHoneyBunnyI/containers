#ifndef rEDBLACKTrEE_HPP
#define rEDBLACKTrEE_HPP

#include "enable_if.hpp"
#include <iostream>

namespace ft
{
enum rb_tree_color { red = false, black = true };

template <class T>
class rb_tree_node
{
	public:
		T val;
		rb_tree_node<T>* parent;
		rb_tree_node<T>* left;
		rb_tree_node<T>* right;
		rb_tree_color color;
	
};

template <class T>
class rb_tree_iterator
{

};

template <class T>
class rb_tree_const_iterator
{

};

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
class redBlackTree
{
	typedef typename Alloc::template rebind<rb_tree_node<Val> >::other _Node_allocator;
	public:
		typedef Key key_type;
		typedef Val value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef rb_tree_node<Val>* node_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
		typedef rb_tree_iterator<value_type> iterator;
		typedef rb_tree_const_iterator<value_type> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef Compare key_compare;
};


}
#endif
