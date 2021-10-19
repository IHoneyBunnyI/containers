#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "RedBlackTree.hpp"
#include "pair_first.hpp"

namespace ft
{


template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef pair<const Key, T> value_type;


	class value_compare
	{
	private:
		Compare _comp;
		value_compare(Compare c) : _comp(c) {}

	public:
		bool operator()(const value_type& a, const value_type& b) const
		{
			return _comp(a.first, b.first);
		}

	};

private:
	typedef typename Allocator::template rebind<value_type>::other pair_alloc_type;
	typedef typename ft::RedBlackTree<Key, value_type, pair_first<value_type>, key_compare, pair_alloc_type> tree_type;
	tree_type rb_tree;

public:
	typedef typename pair_alloc_type::reference reference;
	typedef typename pair_alloc_type::const_reference const_reference;
	typedef typename pair_alloc_type::pointer pointer;
	typedef typename pair_alloc_type::const_pointer const_pointer;
	typedef typename tree_type::iterator iterator;
	typedef typename tree_type::const_iterator const_iterator;
	typedef typename tree_type::reverse_iterator reverse_iterator;
	typedef typename tree_type::const_reverse_iterator const_reverse_iterator;
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;
};

}
#endif
