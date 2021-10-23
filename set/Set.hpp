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
	typedef typename ft::RedBlackTree<key_type, value_type, get_value<value_type>, key_compare, allocator_type> tree_type;
	tree_type tree;
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
	allocator_type get_allocator() const;

};

template <class Key, class T, class Compare, class Alloc>
bool operator== (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);
template <class Key, class T, class Compare, class Alloc>
bool operator!= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);
template <class Key, class T, class Compare, class Alloc>
bool operator<  (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);
template <class Key, class T, class Compare, class Alloc>
bool operator<= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);
template <class Key, class T, class Compare, class Alloc>
bool operator>  (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);
template <class Key, class T, class Compare, class Alloc>
bool operator>= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs);

}
#endif
