#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include "RedBlackTreeNode.hpp"
#include "RedBlackTreeConstIterator.hpp"
#include "RedBlackTreeIterator.hpp"
#include "ReverseIterator.hpp"
#include "pair.hpp"

#define RB_TREE RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>

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
		typedef RedBlackTreeNode<Val>* link_type;
		typedef const RedBlackTreeNode<Val>* const_link_type;
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
		KeyOfValue keyOfvalue;

		void initialize()
		{
			this->head.color = red;
			this->head.parent = 0;
			this->head.right = &this->head;
			this->head.left = &this->head;
			this->count = 0;
		}

		//Private
		link_type _copy(const_link_type x, link_type p);
		link_type _clone_node(const_link_type x);
		link_type _create_node(const value_type& x);
		void _erase(link_type x);
		void _destroy_node(link_type p);
		iterator _insert(link_type x, link_type p, const Val& v);
		void _insert_and_rebalance(const bool insert_left, link_type x, link_type p);

	public:
		//Constructors
		RedBlackTree();
		RedBlackTree(const Compare& comp, const allocator_type& a = allocator_type());
		RedBlackTree(const RedBlackTree& x);
		//Destructor
		~RedBlackTree();


		//MEMBER FUNCTIONS
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		ft::pair<iterator, bool> insert(const Val& v); //NO
		iterator insert(const_iterator position, const Val& v); //NO
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last); //NO

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

//Private:
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_destroy_node(link_type p)
{
	this->allocator_value.destroy(&(p->val));
	this->allocator_node.deallocate(p, 1);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_erase(link_type x)
{
	while (x)
	{
		_erase(x->right);
		link_type y = x->left;
		_destroy_node(x);
		x = y;
	}
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::link_type RB_TREE::_create_node(const value_type& x)
{
	link_type tmp = allocator_node.allocate(1);
	allocator_value.construct(&tmp->val, x);
	return tmp;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::link_type RB_TREE::_clone_node(const_link_type x)
{
	link_type tmp = _create_node(x->val);
	tmp->color = x->color;
	tmp->left = 0;
	tmp->right = 0;
	return tmp;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::link_type RB_TREE::_copy(const_link_type x, link_type p)
{
	link_type top = _clone_node(x);
	top->parent = p;
	if (x->right)
		top->right = _copy(x->right, top);
	p = top;
	x = x->left;
	while (x)
	{
		link_type y = _clone_node(x);
		p->left = y;
		y->parent = p;
		if (x->right)
			y->right = _copy(x->right, y);
		p = y;
		x = x->left;
	}
	return top;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::_insert(link_type x, link_type p, const Val& v)
{
	bool insert_left = (x != 0 || p == &head || compare(keyOfvalue(v), keyOfvalue(p->val)));
	link_type z = _create_node(v);
	_insert_and_rebalance(insert_left, z, p);
	count++;
	return iterator(z);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_insert_and_rebalance(const bool insert_left, link_type x, link_type p)
{
	x->parent = p;
	x->left = 0;
	x->right = 0;
	x->color = red;
}

//Constructors
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE::RedBlackTree()
: head(), count(0), allocator_node(), allocator_value(), compare()
{
	initialize();
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE::RedBlackTree(const Compare& comp, const allocator_type& a): compare(comp), allocator_value(a) {}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE::RedBlackTree(const RedBlackTree& x)
{
	if (x.head.parent)
	{
		this->head.parent = _copy(x.head.parent, &head);
		this->head.left = RedBlackTreeNode<Val>::minimum(head.parent);
		this->head.right = RedBlackTreeNode<Val>::maximum(head.parent);
		this->count = x.count;
	 }
	else
		initialize();
}


//Destructor
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE::~RedBlackTree()
{
	_erase(this->head.parent);
}

/// ITERATORS
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::begin()
{
	return iterator(this->head.left);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::begin() const
{
	return const_iterator(this->head.left);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::end()
{
	return iterator(&(this->head));
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::end() const
{
	return const_iterator(&(this->head));
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::reverse_iterator RB_TREE::rbegin()
{
	return reverse_iterator(end());
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_reverse_iterator RB_TREE::rbegin() const
{
	return const_reverse_iterator(end());
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::reverse_iterator RB_TREE::rend()
{
	return reverse_iterator(begin());
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_reverse_iterator RB_TREE::rend() const
{
	return const_reverse_iterator(begin());
}
//ITERATORS_END

//MEMBER FUNCTIONS
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
bool RB_TREE::empty() const
{
	return this->count == 0;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::size_type RB_TREE::size() const
{
	return this->count;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::size_type RB_TREE::max_size() const
{
	return this->allocator_node.max_size();
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
ft::pair<typename RedBlackTree<Key, Val, KeyOfValue, Compare, Alloc>::iterator, bool> RB_TREE::insert(const Val& v) //ok
{
	link_type x = head.parent;
	link_type y = &head;
	bool comp = true;

	while (x)
	{
		y = x;
		comp = compare(keyOfvalue(v), keyOfvalue(x->val));
		x = comp ? x->left : x->right;
	}
	iterator j = iterator(y);
	if (comp)
	{
		if (j == begin())
			return pair<iterator, bool>(_insert(x, y, v), true);
		else
			--j;
	}
	if (compare(keyOfvalue(j.node->val), keyOfvalue(v)))
		return pair<iterator, bool>(_insert(x, y, v), true);
	return pair<iterator, bool>(j, false);
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
