#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "enable_if.hpp"
#include <iostream>

namespace ft
{
enum rb_tree_color { RED = false, BLACK = true };


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
class RedBlackTree
{
	typedef typename Alloc::template rebind<Rb_tree_node<Val> >::other _Node_allocator;
	public:
		typedef Key key_type;
		typedef Val value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef Rb_tree_node<Val>* node_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
		typedef Rb_tree_iterator<value_type> iterator;
		typedef Rb_tree_const_iterator<value_type> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef Compare key_compare;
};


}
#endif
