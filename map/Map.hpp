#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "RedBlackTree.hpp"
#include "pair_first.hpp"

#define MAP map<Key, T, Compare, Allocator>

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
	//Destructor
	~map();


	//OPERATOR OVERFLOW
	map& operator= (const map& x); //////////////NO

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
	mapped_type& operator[] (const key_type& k); /////////////NO


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

	//Constructors
template <class Key, class T, class Compare, class Allocator>
MAP::map(const key_compare& comp, const allocator_type& alloc): rb_tree(comp, alloc) {}

template <class Key, class T, class Compare, class Allocator>
MAP::map(const map& x): rb_tree(x.rb_tree){}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
MAP::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : rb_tree(comp, alloc)
{
	this->rb_tree.insert(first, last);
}
//Destructor
template <class Key, class T, class Compare, class Allocator>
MAP::~map()
{
	~rb_tree;
}

//OPERATOR OVERFLOW
template <class Key, class T, class Compare, class Allocator>
MAP& MAP::operator= (const map& x)
{
	this->rb_tree = x.rb_tree;
	return (*this);
}

//Iterators
template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::begin()
{
	return this->rb_tree.begin();
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::const_iterator MAP::begin() const
{
	return this->rb_tree.begin();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::end()
{
	return this->rb_tree.end();
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::const_iterator MAP::end() const
{
	return this->rb_tree.end();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::reverse_iterator MAP::rbegin()
{
	return this->rb_tree.rbegin();
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::const_reverse_iterator MAP::rbegin() const
{
	return this->rb_tree.rbegin();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::reverse_iterator MAP::rend()
{
	return this->rb_tree.rend();
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::const_reverse_iterator MAP::rend() const
{
	return this->rb_tree.rend();
}

//CAPACITY
template <class Key, class T, class Compare, class Allocator>
bool MAP::empty() const
{
	return this->rb_tree.empty();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::size_type MAP::size() const
{
	return this->rb_tree.size();
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::size_type MAP::max_size() const
{
	return this->rb_tree.max_size();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::mapped_type& MAP::operator[] (const key_type& k)
{

}

template <class Key, class T, class Compare, class Allocator>
typename ft::pair<typename MAP::iterator,bool> MAP::insert(const value_type& val)
{
	return this->rb_tree.insert(val);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::insert(iterator position, const value_type& val)
{
	return this->rb_tree.insert(position, val);
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator> 
void MAP::insert(InputIterator first, InputIterator last)
{
	this->rb_tree.insert(first, last);
}

template <class Key, class T, class Compare, class Allocator>
void MAP::erase(iterator position)
{
	this->rb_tree.erase(position);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::size_type MAP::erase(const key_type& k)
{
	return this->rb_tree.erase(k);
}

template <class Key, class T, class Compare, class Allocator>
void MAP::erase(iterator first, iterator last)
{
	return this->rb_tree.erase(first, last);
}

template <class Key, class T, class Compare, class Allocator>
void MAP::swap(map& x)
{
	this->rb_tree.swap(x);
}

template <class Key, class T, class Compare, class Allocator>
void MAP::clear()
{
	this->rb_tree.clear();
}

//Observers:
template <class Key, class T, class Compare, class Allocator>
typename MAP::key_compare MAP::key_comp() const
{
	return this->rb_tree.key_comp();
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::value_compare MAP::value_comp() const
{
	return value_compare(this->rb_tree.key_comp());
}

//Operations:
template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::find(const key_type& k)
{
	return this->rb_tree.find(k);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::const_iterator MAP::find(const key_type& k) const
{
	return this->rb_tree.find(k);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::size_type MAP::count(const key_type& k) const
{
	return this->rb_tree.count(k);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::lower_bound(const key_type& k)
{
	return this->rb_tree.lower_bound(k);
}
template <class Key, class T, class Compare, class Allocator>
typename MAP::const_iterator MAP::lower_bound(const key_type& k) const
{
	return this->rb_tree.lower_bound(k);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::iterator MAP::upper_bound(const key_type& k)
{
	return this->rb_tree.upper_bound(k);
}

template <class Key, class T, class Compare, class Allocator>
typename MAP::const_iterator MAP::upper_bound(const key_type& k) const
{
	return this->rb_tree.upper_bound(k);
}

template <class Key, class T, class Compare, class Allocator>
pair<typename MAP::const_iterator,typename MAP::const_iterator> MAP::equal_range(const key_type& k) const
{
	return this->rb_tree.equal_range();
}

template <class Key, class T, class Compare, class Allocator>
pair<typename MAP::iterator,typename MAP::iterator> MAP::equal_range(const key_type& k)
{
	return this->rb_tree.equal_range();
}

//Allocator:
template <class Key, class T, class Compare, class Allocator>
typename MAP::allocator_type MAP::get_allocator() const
{
	return this->rb_tree.get_allocator();
}

}
#endif
