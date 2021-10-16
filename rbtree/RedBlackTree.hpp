#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include "RedBlackTreeNode.hpp"
#include "RedBlackTreeConstIterator.hpp"
#include "RedBlackTreeIterator.hpp"
#include "ReverseIterator.hpp"

namespace ft
{

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
class RedBlackTree
{
	typedef typename Alloc::template rebind<RedBlackTreeNode<Val> >::other node_allocator;
	public:
		typedef Key key_type;
		typedef Val value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef RedBlackTreeNode<Val>* node_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
		typedef RedBlackTreeIterator<value_type> iterator;
		typedef RedBlackTreeConstIterator<value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef Compare key_compare;

	private:
		RedBlackTreeNode<value_type> head;
		size_type count;
		node_allocator allocator_node;
		allocator_type allocator_value;
		key_compare compare;

		void initialize()
		{
			this->head.color = red;
			this->head.parent = 0;
			this->head.right = this->head;
			this->head.left = this->head;
			this->size = 0;
		}

	public:
		//Constructors
		RedBlackTree();
		RedBlackTree(const Compare& comp, const allocator_type& a = allocator_type());


		//MEMBER FUNCTIONS
		bool empty() const;
		size_type size() const;

		//ITERATORS
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
};


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::RedBlackTree()
: head(), count(0), allocator_node(), allocator_value(), compare()
{
	initialize();
}


//typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::RedBlackTree(const Compare& comp, const allocator_type& a): compare(comp), allocator_value(a) {}





/// ITERATORS
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::begin()
{
	return iterator(this->head.left);
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::begin() const
{
	return const_iterator(this->head.left);
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::end()
{
	return iterator(&(this->head));
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::const_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::end() const
{
	return const_iterator(&(this->head));
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::reverse_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::rbegin()
{
	return reverse_iterator(end());
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::const_reverse_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(end());
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::reverse_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::rend()
{
	return reverse_iterator(begin());
}
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::const_reverse_iterator RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(begin());
}
//ITERATORS_END


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
bool RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::empty() const
{
	return this->count == 0;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::size_type RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::size() const
{
	return this->count;
}

//Overloads
template<typename T>
bool operator==(const RedBlackTreeIterator<T>& x, const RedBlackTreeConstIterator<T>& y)
{
	return x.node == y.node;
}
 
template<typename T>
bool operator!=(const RedBlackTreeIterator<T>& x, const RedBlackTreeConstIterator<T>& y)
{
	return x.node != y.node;
}

}
#endif
