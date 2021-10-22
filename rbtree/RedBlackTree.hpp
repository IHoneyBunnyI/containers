#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include "RedBlackTreeNode.hpp"
#include "RedBlackTreeConstIterator.hpp"
#include "RedBlackTreeIterator.hpp"
#include "ReverseIterator.hpp"
#include "pair.hpp"
#include <iomanip>

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
		size_type count_node;
		node_allocator allocator_node;
		allocator_type allocator_value;
		key_compare compare;
		KeyOfValue keyOfvalue;

		//Private
		void initialize();
		link_type _copy(const_link_type x, link_type p);
		link_type _clone_node(const_link_type x);
		link_type _create_node(const value_type& x);
		void _erase(link_type x);
		void _destroy_node(link_type p);
		iterator _insert(const_link_type x, const_link_type p, const Val& v);
		void _insert_and_rebalance(const bool insert_left, link_type x, link_type p);
		void _rotate_right(link_type x);
		void _rotate_left(link_type x);
		iterator _lower_bound(link_type x, link_type y, const Key& k);
		const_iterator _lower_bound(const_link_type x, const_link_type y, const Key& k) const;
		iterator _upper_bound(link_type x, link_type y, const Key& k);
		const_iterator _upper_bound(const_link_type x, const_link_type y, const Key& k) const;
		void _erase_aux(const_iterator position);
		link_type _rebalance_for_erase(link_type z);

	public:
		//Constructors
		RedBlackTree();
		RedBlackTree(const Compare& comp, const allocator_type& a = allocator_type());
		RedBlackTree(const RedBlackTree& x);
		//Destructor
		~RedBlackTree();

		//OVERLOADS
		RedBlackTree& operator = (const RedBlackTree& x);

		//MEMBER FUNCTIONS
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void clear();
		size_type count(const key_type& k) const;
		Compare key_comp() const;

		ft::pair<iterator, bool> insert(const Val& v);
		iterator insert(const_iterator position, const Val& v);
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last);

		void erase(iterator position); ///////////////
		void erase(const_iterator position);
		size_type erase(const key_type& x);
		void erase (iterator first, iterator last);
		void erase (const_iterator first, const_iterator last);

		iterator find(const Key& k);
		const_iterator find(const Key& k) const;

		iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;
		iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;
		pair<iterator, iterator> equal_range(const key_type& k);
		pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
		void swap(RedBlackTree& t);
		allocator_type get_allocator() const;

		//ITERATORS
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		///VISUALIZATOR
	public:
		void printTree();
	private:
		void postorder(link_type p, int indent);
};




//PRIVATE:
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::initialize()
{
	this->head.color = red;
	this->head.parent = 0;
	this->head.right = &this->head;
	this->head.left = &this->head;
	this->count_node = 0;
}

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
typename RB_TREE::iterator RB_TREE::_insert(const_link_type x, const_link_type p, const Val& v)
{
	bool insert_left = (x != 0 || p == &head || compare(keyOfvalue(v), keyOfvalue(p->val)));
	link_type z = _create_node(v);
	_insert_and_rebalance(insert_left, z, const_cast<link_type>(p));
	count_node++;
	return iterator(z);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_insert_and_rebalance(const bool insert_left, link_type x, link_type p)
{
	x->parent = p;
	x->left = 0;
	x->right = 0;
	x->color = red;

	if (insert_left)
	{
		p->left = x;
		if (p == &head)
		{
			head.parent = x;
			head.right = x;
		}
		else if (p == head.left)
			head.left = x;
	}
	else
	{
		p->right = x;
		if (p == head.right)
			head.right = x;
	}
	//Rebalance
	while (x != this->head.parent && x->parent->color == red)
	{
		link_type xpp = x->parent->parent;
		if (x->parent == xpp->left)
		{
			link_type y = xpp->right;
			if (y && y->color == red)
			{
				x->parent->color = black;
				y->color = black;
				xpp->color = red;
				x = xpp;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					_rotate_left(x);
				}
				x->parent->color = black;
				xpp->color = red;
				_rotate_right(xpp);
			}
		}
		else
		{
			link_type y = xpp->left;
			if (y && y->color == red)
			{
				x->parent->color = black;
				y->color = black;
				xpp->color = red;
				x = xpp;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					_rotate_right(x);
				}
				x->parent->color = black;
				xpp->color = red;
				_rotate_left(xpp);
			}
		}
	}
	this->head.parent->color = black;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_rotate_right(link_type x)
{
	link_type y = x->left;
	x->left = y->right;
	if (y->right != 0)
		y->right->parent = x;
	y->parent = x->parent;
	if (x == this->head.parent)
		this->head.parent = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_rotate_left(link_type x)
{
	link_type y = x->right;
	x->right = y->left;
	if (y->left != 0)
		y->left->parent = x;
	y->parent = x->parent;
	if (x == head.parent)
		head.parent = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::_lower_bound(link_type x, link_type y, const Key& k)
{
	while (x != 0)
	{
		if (!compare(keyOfvalue(x->val), k))
			y = x, x = x->left;
		else
			x = x->right;
	}
	return iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::_lower_bound(const_link_type x, const_link_type y, const Key& k) const
{
	while (x != 0)
	{
		if (!compare(keyOfvalue(x->val), k))
			y = x, x = x->left;
		else
			x = x->right;
	}
	return const_iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::_upper_bound(link_type x, link_type y, const Key& k)
{
	while (x != 0)
	{
		if (compare(k, keyOfvalue(x->val)))
			y = x, x = x->left;
		else
			x = x->right;
	}
	return iterator(y);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::_upper_bound(const_link_type x, const_link_type y, const Key& k) const
{
	while (x != 0)
	{
		if (compare(k, keyOfvalue(x->val)))
			y = x, x = x->left;
		else
			x = x->right;
	}
	return const_iterator(y);
}


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::_erase_aux(const_iterator position)
{
	link_type y = _rebalance_for_erase(const_cast<link_type>(position.node));
	_destroy_node(y);
	--this->count_node;
}

//Constructors
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE::RedBlackTree()
: head(), count_node(0), allocator_node(), allocator_value(), compare()
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
		this->count_node = x.count_node;
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
	return this->count_node == 0;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::size_type RB_TREE::size() const
{
	return this->count_node;
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

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::insert(const_iterator position, const Val& v)
{
	if (position.node == &head)
	{
		if (this->size() > 0 && compare(head.right->val.first, keyOfvalue(v)))
			return _insert(0, head.right, v);
		else
			return insert(v).first;
	}
	else if (compare(keyOfvalue(v), position->first))
	{
		const_iterator before = position;
		--before;
		if (position.node == head.left)
			return _insert(head.left, head.left, v);
		else if (compare(before->first, keyOfvalue(v)))
		{
			if (before.node->right == 0)
				return _insert(0, before.node, v);
			else
				return _insert(position.node, position.node, v);
		}
		else
			return insert(v).first;

	}
	else if (compare(position->first, keyOfvalue(v)))
	{
		const_iterator after = position;
		++after;
		if (position.node == head.right)
			return _insert(0, head.right, v);
		else if (compare(keyOfvalue(v), after->first))
		{
			if (position.node->right == 0)
				return _insert(0, position.node, v);
			else
				return _insert(after.node, after.node, v);
		}
		else
			return insert(v).first;
	}
	return iterator(const_cast<typename iterator::link_type>(position.node)); //ШИКОС
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
template<class InputIterator>
void RB_TREE::insert(InputIterator first, InputIterator last)
{
	for (; first != last; ++first)
		insert(end(), *first);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::find(const Key& k)
{
	iterator j  = _lower_bound(this->head.parent, &this->head, k);
	return (j == end() || compare(k, keyOfvalue(j.node->val))) ? end() : j;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::find(const Key& k) const
{
	const_iterator j  = _lower_bound(this->head.parent, &this->head, k);
	return (j == end() || compare(k, keyOfvalue(j.node->val))) ? end() : j;
}


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::lower_bound(const key_type& k)
{
	return _lower_bound(this->head.parent, &head, k);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::lower_bound(const key_type& k) const
{
	return _lower_bound(this->head.parent, &head, k);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::iterator RB_TREE::upper_bound(const key_type& k)
{
	return _upper_bound(this->head.parent, &head, k);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::const_iterator RB_TREE::upper_bound(const key_type& k) const
{
	return _upper_bound(this->head.parent, &head, k);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::clear()
{
	_erase(this->head.parent);
	this->head.left = &this->head;
	this->head.parent = 0;
	this->head.right = &head;
	this->count_node = 0;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::size_type RB_TREE::count(const key_type& k) const
{
	ft::pair<const_iterator, const_iterator> p = equal_range(k);
	const size_type n = std::distance(p.first, p.second);
	return n;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
ft::pair<typename RB_TREE::iterator, typename RB_TREE::iterator> RB_TREE::equal_range(const key_type& k)
{
	link_type x = this->head.parent;
	link_type y = &this->head;
	while (x != 0)
	{
		if (compare(keyOfvalue(x->val), k))
			x = x->right;
		else if (compare(k, keyOfvalue(x->val)))
			y = x, x = x->left;
		else
		{
			link_type xu(x), yu(y);
			y = x, x = x->left;
			xu = xu->right;
			return ft::pair<iterator, iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
		}
	}
	return ft::pair<iterator, iterator>(iterator(y), iterator(y));
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
ft::pair<typename RB_TREE::const_iterator, typename RB_TREE::const_iterator> RB_TREE::equal_range(const key_type& k) const
{
	const_link_type x = this->head.parent;
	const_link_type y = &this->head;
	while (x != 0)
	{
		if (compare(keyOfvalue(x->val), k))
			x = x->right;
		else if (compare(k, keyOfvalue(x->val)))
			y = x, x = x->left;
		else
		{
			const_link_type xu(x), yu(y);
			y = x, x = x->left;
			xu = xu->right;
			return ft::pair<const_iterator, const_iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k));
		}
	}
	return ft::pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
}


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::swap(RedBlackTree& t)
{
	if (this->head.parent == 0)
	{
		if (t.head.parent != 0)
		{
			this->head.parent = t.head.parent;
			this->head.left = t.head.left;
			this->head.right = t.head.right;
			this->head.parent->parent = &head;

			t.head.parent = 0;
			t.head.left = &t.head;
			t.head.right = &t.head;
		}
	}
	else if (t.head.parent == 0)
	{
		t.head.parent = this->head.parent;
		t.head.left = this->head.left;
		t.head.right = this->head.right;
		t.head.parent.parent = &t.head;

		this->head.parent = 0;
		this->head.left = &this->head;
		this->head.right = &this->head;
	}
	else
	{
		std::swap(this->head.parent, t.head.parent);
		std::swap(this->head.left, t.head.left);
		std::swap(this->head.right, t.head.right);

		this->head.parent.parent = &this->head;
		t.head.parent.parent = &t.head;
	}
	std::swap(this->count_node, t.count_node);
	std::swap(this->compare, t.compare);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
Compare RB_TREE::key_comp() const
{
	return compare;
}


template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::allocator_type RB_TREE::get_allocator() const
{
	return allocator_node;
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::erase(iterator position)
{
	_erase_aux(position);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::erase(const_iterator position)
{
	_erase_aux(position);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::size_type RB_TREE::erase(const key_type& x)
{
	pair<iterator, iterator> p = equal_range(x);
	const size_type old_size = this->size();
	erase(p.first, p.second);
	return old_size - this->size();
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::erase (iterator first, iterator last) 
{
	if (first == begin() && last == end())
		clear();
	else
		while (first != last)
			erase(first++);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::erase (const_iterator first, const_iterator last)
{
	if (first == begin() && last == end())
		clear();
	else
		while (first != last)
			erase(first++);
}

//OVERLOADS
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

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
RB_TREE& RB_TREE::operator = (const RedBlackTree& x)
{
	if (this != &x)
	{
		this->clear();
		this->compare = x.compare;
		if (x.head.parent)
		{
			this->head.parent = _copy(x.head.parent, &head);
			this->head.left = RedBlackTreeNode<Val>::minimum(head.parent);
			this->head.right = RedBlackTreeNode<Val>::maximum(head.parent);
			this->count_node = x.count_node;
		}
	}
	return *this;
}

//VISUALIZATOR
template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::postorder(link_type p, int indent)
{
	if (p != NULL)
	{
		if (p->right) 
			postorder(p->right, indent+4);
		if (indent) 
			std::cout << std::setw(indent) << ' ';
		if (p->right)
			std::cout<<" /\n" << std::setw(indent) << ' ';
		std::cout << (p->color == red ? "\033[1;38;5;9m" : "\033[1;38;5;238m") <<  p->val.first << "\033[0m" << std::endl;
		if(p->left)
		{
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			postorder(p->left, indent+4);
		}
	}
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
void RB_TREE::printTree()
{
	postorder(this->head.parent, 1);
}

template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc>
typename RB_TREE::link_type RB_TREE::_rebalance_for_erase(link_type z)
{
	link_type& root = this->head.parent;
	link_type& leftmost = this->head.left;
	link_type& rightmost = this->head.right;
	link_type y = z;
	link_type x = 0;
	link_type x_parent = 0;

	if (y->left == 0)
		x = y->right;
	else
	{
		if (y->right == 0)
			x = y->left;
		else
		{
			y = y->right;
			while (y->left != 0)
				y = y->left;
			x = y->right;
		}
	}
	if (y != z)
	{
		z->left->parent = y;
		y->left = z->left;
		if (y != z->right)
		{
			x_parent = y->parent;
			if (x) x->parent = y->parent;
			y->parent->left = x;
			y->right = z->right;
			z->right->parent = y;
		}
		else
			x_parent = y;
		if (root == z)
			root = y;
		else if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;
		y->parent = z->parent;
		std::swap(y->color, z->color);
		y = z;
	}
	else
	{
		x_parent = y->parent;
		if (x)
			x->parent = y->parent;
		if (root == z)
			root = x;
		else
		{
			if (z->parent->left == z)
				z->parent->left = x;
			else
				z->parent->right = x;
		}
		if (leftmost == z)
		{
			if (z->right == 0)
				leftmost = z->parent;
			else
				leftmost = RedBlackTreeNode<value_type>::minimum(x);
		}
		if (rightmost == z)
		{
			if (z->left == 0)
				rightmost = z->parent;
			else
				rightmost = RedBlackTreeNode<value_type>::maximum(x);
		}
	}
	if (y->color != red)
	{
		while (x != root && (x == 0 || x->color == black))
		{
			if (x == x_parent->left)
			{
				link_type w = x_parent->right;
				if (w->color == red)
				{
					w->color = black;
					x_parent->color = red;
					_rotate_left(x_parent);
					w = x_parent->right;
				}
				if ((w->left == 0 || w->left->color == black) && (w->right == 0 || w->right->color == black))
				{
					w->color = red;
					x = x_parent;
					x_parent = x_parent->parent;
				}
				else
				{
					if (w->right == 0 || w->right->color == black)
					{
						w->left->color = black;
						w->color = red;
						_rotate_right(w);
						w = x_parent->right;
					}
					w->color = x_parent->color;
					x_parent->color = black;
					if (w->right)
						w->right->color = black;
					_rotate_left(x_parent);
					break;
				}
			}
			else
			{
				link_type w = x_parent->left;
				if (w->color == red)
				{
					w->color = black;
					x_parent->color = red;
					_rotate_right(x_parent);
					w = x_parent->left;
				}
				if ((w->right == 0 || w->right->color == black) && (w->left == 0 || w->left->color == black))
				{
					w->color = red;
					x = x_parent;
					x_parent = x_parent->parent;
				}
				else
				{
					if (w->left == 0 || w->left->color == black)
					{
						w->right->color = black;
						w->color = red;
						_rotate_left(w);
						w = x_parent->left;
					}
					w->color = x_parent->color;
					x_parent->color = black;
					if (w->left)
						w->left->color = black;
					_rotate_right(x_parent);
					break;
				}
			}
		}
		if (x)
			x->color = black;
	}
	return y;
}

}
#endif
