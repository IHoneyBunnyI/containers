#ifndef SET_HPP
#define SET_HPP
#include <iostream>
#include "../rbtree/RedBlackTree.hpp"
#include "../../utils/get_value.hpp"
#define SET set<T, Compare, Allocator>

namespace ft
{

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class set
{
public:
	typedef T key_type;
	typedef T value_type;
	typedef Compare key_compare;
	typedef Compare value_compare;
	typedef Allocator allocator_type;
 private:
	typedef typename ft::RedBlackTree<key_type, value_type, get_value<value_type>, key_compare, allocator_type> tree_type;
	tree_type rb_tree;
public:
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename tree_type::iterator iterator;
	typedef typename tree_type::const_iterator const_iterator;
	typedef typename tree_type::reverse_iterator reverse_iterator;
	typedef typename tree_type::const_reverse_iterator const_reverse_iterator;
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;

	//Constructors
	explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
  	set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	set(const set& x);
	//Destructor
	~set();

	//OPERATOR =
	set& operator= (const set& x);

	//Iterators
	iterator begin();
	const_iterator begin() const;

	iterator end();
	const_iterator end() const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	reverse_iterator rend();
	const_reverse_iterator rend() const;

	//Capacity:
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	//Modifiers:
	pair<iterator,bool> insert(const value_type& val);
	iterator insert(iterator position, const value_type& val);
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);

	void erase(iterator position);
	size_type erase(const value_type& val);
	void erase(iterator first, iterator last);
	void swap(set& x);
	void clear();

	//Observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	//Operations:
	iterator find(const value_type& val) const;
	size_type count(const value_type& val) const;
	iterator lower_bound(const value_type& val) const;
	iterator upper_bound(const value_type& val) const;
	pair<iterator,iterator> equal_range(const value_type& val) const;

	//Allocator:
	allocator_type get_allocator() const;

	//non-member overloads:
	template <class _T, class _Compare, class _Alloc>
	friend bool operator == (const set<_T, _Compare, _Alloc>& lhs, const set<_T, _Compare, _Alloc>& rhs);
	template <class _T, class _Compare, class _Alloc>
	friend bool operator < (const set<_T, _Compare, _Alloc>& lhs, const set<_T, _Compare, _Alloc>& rhs);

};

//Constructors
template <class T, class Compare, class Allocator>
SET::set(const key_compare& comp, const allocator_type& alloc): rb_tree(comp, alloc) {}

template <class T, class Compare, class Allocator>
template <class InputIterator>
SET::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : rb_tree(comp, alloc)
{
	this->rb_tree.insert(first, last);
}

template <class T, class Compare, class Allocator>
SET::set(const set& x) : rb_tree(x.rb_tree) {}

//Destructor
template <class T, class Compare, class Allocator>
SET::~set()
{
	~rb_tree;
}

//OPERATOR =
template <class T, class Compare, class Allocator>
SET& SET::operator= (const set& x)
{
	this->rb_tree = x.rb_tree;
	return (*this);
}

//Iterators
template <class T, class Compare, class Allocator>
typename SET::iterator SET::begin()
{
	return this->rb_tree.begin();
}
template <class T, class Compare, class Allocator>
typename SET::const_iterator SET::begin() const
{
	return this->rb_tree.begin();
}

template <class T, class Compare, class Allocator>
typename SET::iterator SET::end()
{
	return this->rb_tree.end();
}
template <class T, class Compare, class Allocator>
typename SET::const_iterator SET::end() const
{
	return this->rb_tree.end();
}

template <class T, class Compare, class Allocator>
typename SET::reverse_iterator SET::rbegin()
{
	return this->rb_tree.rbegin();
}
template <class T, class Compare, class Allocator>
typename SET::const_reverse_iterator SET::rbegin() const
{
	return this->rb_tree.rbegin();
}

template <class T, class Compare, class Allocator>
typename SET::reverse_iterator SET::rend()
{
	return this->rb_tree.rend();
}
template <class T, class Compare, class Allocator>
typename SET::const_reverse_iterator SET::rend() const
{
	return this->rb_tree.rend();
}

//CAPACITY
template <class T, class Compare, class Allocator>
bool SET::empty() const
{
	return this->rb_tree.empty();
}

template <class T, class Compare, class Allocator>
typename SET::size_type SET::size() const
{
	return this->rb_tree.size();
}
template <class T, class Compare, class Allocator>
typename SET::size_type SET::max_size() const
{
	return this->rb_tree.max_size();
}

//Modifiers:
template <class T, class Compare, class Allocator>
typename ft::pair<typename SET::iterator,bool> SET::insert(const value_type& val)
{
	return this->rb_tree.insert(val);
}

template <class T, class Compare, class Allocator>
typename SET::iterator SET::insert(iterator position, const value_type& val)
{
	return this->rb_tree.insert(position, val);
}

template <class T, class Compare, class Allocator>
template <class InputIterator> 
void SET::insert(InputIterator first, InputIterator last)
{
	this->rb_tree.insert(first, last);
}

template <class T, class Compare, class Allocator>
void SET::erase(iterator position)
{
	this->rb_tree.erase(position);
}

template <class T, class Compare, class Allocator>
typename SET::size_type SET::erase(const value_type& k)
{
	return this->rb_tree.erase(k);
}

template <class T, class Compare, class Allocator>
void SET::erase(iterator first, iterator last)
{
	return this->rb_tree.erase(first, last);
}

template <class T, class Compare, class Allocator>
void SET::swap(set& x)
{
	this->rb_tree.swap(x);
}

template <class T, class Compare, class Allocator>
void SET::clear()
{
	this->rb_tree.clear();
}

//Observers:
template <class T, class Compare, class Allocator>
typename SET::key_compare SET::key_comp() const
{
	return this->rb_tree.key_comp();
}

template <class T, class Compare, class Allocator>
typename SET::value_compare SET::value_comp() const
{
	return value_compare(this->rb_tree.key_comp());
}


//Operations:
template <class T, class Compare, class Allocator>
typename SET::iterator SET::find(const value_type& val) const
{
	return this->rb_tree.find(val);
}
template <class T, class Compare, class Allocator>
typename SET::size_type SET::count(const value_type& val) const
{
	return this->rb_tree.count(val);
}
template <class T, class Compare, class Allocator>
typename SET::iterator SET::lower_bound(const value_type& val) const
{
	return this->rb_tree.lower_bound(val);
}
template <class T, class Compare, class Allocator>
typename SET::iterator SET::upper_bound(const value_type& val) const
{
	return this->rb_tree.upper_bound(val);
}
template <class T, class Compare, class Allocator>
typename ft::pair<typename SET::iterator, typename SET::iterator> SET::equal_range(const value_type& val) const
{
	return this->rb_tree.equal_range(val);
}
template <class T, class Compare, class Allocator>
typename SET::allocator_type SET::get_allocator() const
{
	return this->rb_tree.get_allocator();
}

template <class T, class Compare, class Allocator>
bool operator== (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return lhs.rb_tree == rhs.rb_tree;
}
template <class T, class Compare, class Allocator>
bool operator<  (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return lhs.rb_tree < rhs.rb_tree;
}
template <class T, class Compare, class Allocator>
bool operator!= (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return !(lhs == rhs);
}
template <class T, class Compare, class Allocator>
bool operator<= (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return !(rhs < lhs);
}
template <class T, class Compare, class Allocator>
bool operator>  (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return (rhs < lhs);
}
template <class T, class Compare, class Allocator>
bool operator>= (const set<T,Compare,Allocator>& lhs, const set<T,Compare,Allocator>& rhs)
{
	return !(lhs < rhs);
}
template <class T, class Compare, class Allocator>
void swap (set<T,Compare,Allocator>& x, set<T,Compare,Allocator>& y)
{
	x.swap(y);
}

}
#endif
