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


	class value_compare : std::binary_function<value_type, value_type, bool> //in cplusplus.com map->value_compare
	{
	friend class map;
	protected:
		Compare _comp;
		value_compare(Compare c) : _comp(c) {}

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		bool operator()(const value_type& x, const value_type& y) const
		{
			return _comp(x.first, y.first);
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



	//Constructors
	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& x);
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	~map();


	//OPERATOR OVERFLOW
	map& operator= (const map& x);

	//Iterators
	iterator begin();
	const_iterator begin() const;

	iterator end();
	const_iterator end() const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	reverse_iterator rend();
	const_reverse_iterator rend() const;

	//Capacity
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	//Element access:
	mapped_type& operator[] (const key_type& k);


	//Modifiers:
	//
	//INSERT
	pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator> 
	void insert (InputIterator first, InputIterator last);

	//ERASE
	void erase (iterator position);
	size_type erase (const key_type& k);
	void erase (iterator first, iterator last);

	void swap (map& x);
	void clear();

	//Observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	//Operations:
	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;

	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	pair<iterator,iterator> equal_range (const key_type& k);

	//Allocator:
	allocator_type get_allocator() const;
};

}
#endif
