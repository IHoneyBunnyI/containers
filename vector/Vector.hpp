#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "RandomAccessIterator.hpp"
#include "ConstRandomAccessIterator.hpp"
#include "ReverseIterator.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"
#include "lexicographical_compare.hpp"


namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;

		typedef RandomAccessIterator<value_type>				iterator;
		typedef ConstRandomAccessIterator<value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	private:
		value_type* first;
		size_type capacityAllocated;
		size_type length;
		Allocator allocator;

	public:
		//Construcors
		vector();
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template<class InputIt>
		vector(InputIt first, typename ft::enable_if<!ft::is_integral_const<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator());
		vector(const vector& other);
		//Destructor
		~vector();
		//Operator =
		vector& operator = (const vector& x);

		//Iterators:
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//Capacity:
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type new_cap);

		//Element access:
		reference operator [](size_type pos);
		const_reference operator [](size_type pos) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		//Modifiers:
		template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		void assign (size_type n, const value_type& val);
		void push_back(const T& value);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, typename ft::enable_if<!ft::is_integral_const<InputIterator>::value, InputIterator>::type first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

		//Allocator:
		allocator_type get_allocator() const;

};

//=========================Constructors=================================
template <class T, class Allocator>
ft::vector<T, Allocator>::vector() : first(0), capacityAllocated(0), length(0), allocator(allocator_type()) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc) : first(0), capacityAllocated(0), length(0), allocator(alloc) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(ft::vector<T, Allocator>::size_type count, const T& value, const Allocator& alloc) : allocator(alloc)
{
	first = allocator.allocate(count);
	this->capacityAllocated = count;
	this->length = count;
	for (size_type i = 0; i < count; i++)
		allocator.construct(first + i, value);
}

template <class T, class Allocator>
template <class InputIt>
ft::vector<T, Allocator>::vector(InputIt first, typename ft::enable_if<!ft::is_integral_const<InputIt>::value, InputIt>::type last, const Allocator& alloc) : allocator(alloc)
{
	this->length = std::distance(first, last);
	this->capacityAllocated = std::distance(first, last);
	this->first = allocator.allocate(this->capacityAllocated);
	for (size_type i = 0; i < this->length; i++)
		allocator.construct(this->first + i, *(first + i));
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const vector& other): allocator(other.allocator)
{
	this->length = other.length;
	this->capacityAllocated = other.capacityAllocated;
	this->first = allocator.allocate(this->capacityAllocated);
	for (size_type i = 0; i < this->length; i++)
		allocator.construct(this->first + i, *(other.first + i));
}

//=========================Destructor=================================
template <class T, class Allocator>
ft::vector<T, Allocator>::~vector()
{
	if (this->first != 0)
	{
		//for (size_type i = 0; first + i != (this->first + this->length); i++)
			//allocator.destroy(first + i);
		allocator.deallocate(first, this->capacityAllocated);
	}
}

//=========================Member functions=================================
template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::begin() const
{
	return const_iterator(this->first);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin()
{
	return iterator(this->first);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::end() const
{
	return const_iterator(this->first + this->length);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end()
{
	return iterator(this->first + this->length);
}

template <class T, class Allocator>
bool ft::vector<T, Allocator>::empty() const
{
	if (this->length == 0)
		return true;
	return false;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size() const
{
	return this->length;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::max_size() const
{
	return allocator.max_size();
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::capacity() const
{
	return this->capacityAllocated;
}

template <class T, class Allocator>
void vector<T, Allocator>::clear()
{
	if (this->first == 0)
		return ;
	pointer end = this->first + this->size();
	for (pointer tmp = this->first; tmp < end; tmp++)
		allocator.destroy(tmp);
	this->length = 0;
}

template <class T, class Allocator>
template <class InputIterator>
void ft::vector<T, Allocator>::assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
{
	this->clear();
	size_type dist = std::distance(first, last);
	if (dist > this->capacityAllocated)
	{
		allocator.deallocate(this->first, this->capacityAllocated);
		this->capacityAllocated = dist;
		this->length = dist;
		this->first = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; first + i < last; i++)
			allocator.construct(this->first + i, *(first + i));
	}
	else
	{
		this->length = dist;
		for (size_type i = 0; first + i < last; i++)
			allocator.construct(this->first + i, *(first + i));
	}
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::assign (size_type n, const value_type& val)
{
	this->clear();
	if (n > this->capacityAllocated)
	{
		allocator.deallocate(this->first, this->capacityAllocated);
		this->capacityAllocated = n;
		this->length = n;
		this->first = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < n; i++)
			allocator.construct(this->first + i, val);
	}
	else
	{
		this->length = n;
		for (size_type i = 0; i < n; i++)
			allocator.construct(this->first + i, val);
	}
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::at (size_type n)
{
	if (n >= this->length)
		throw std::out_of_range("vector");
	return (*(this->first + n));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::at (typename ft::vector<T,Allocator>::size_type n) const
{
	if (n >= this->length)
		throw std::out_of_range("vector");
	return (*(this->first + n));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::back()
{
	return (*(this->first + (this->length - 1)));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::back() const
{
	return (*(this->first + (this->length - 1)));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase (iterator position)
{
	size_type i = std::distance(iterator(this->first), position);
	allocator.destroy(this->first + i);
	std::copy(position + 1, this->end(), position);
	this->length--;
	return (position);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T,Allocator>::erase (iterator first, iterator last)
{
	size_type dist = std::distance(first, last);
	for (size_type i = 0; i < dist; i++)
		allocator.destroy(this->first + i);
	std::copy(last, this->end(), first);
	this->length -= dist;
	return(first);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::front()
{
	return *this->first;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::front() const
{
	return *this->first;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::allocator_type ft::vector<T, Allocator>::get_allocator() const
{
	return allocator;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::insert (iterator position, const value_type& val)
{
	size_type pos = std::distance(this->begin(), position);
	if (++this->length > this->capacityAllocated)
	{
		this->capacityAllocated *= 2;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = 1;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < pos; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = pos; i < this->length - 1; i++)
			allocator.construct(tmp + i + 1, *(this->first + i));
		allocator.deallocate(this->first, this->length - 1);
		this->first = tmp;
		allocator.construct(this->first + pos, val);
		return position;
	}
	else
	{
		for (size_type i = this->length - 1; i > pos; i--)
			allocator.construct(this->first + i, *(this->first + i - 1));
		size_type i = std::distance(this->begin(), iterator(this->first + pos));
		allocator.destroy(this->first + i);
		allocator.construct(this->first + i, val);
		return position;
	}
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::insert (iterator position, size_type n, const value_type& val)
{
	this->length += n;
	size_type old_capacity = this->capacityAllocated;
	size_type pos = std::distance(this->begin(), position);
	if (this->length > this->capacityAllocated * 2)
	{
		this->capacityAllocated = this->length;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = n;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < pos; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = pos; i < pos + n; i++)
			allocator.construct(tmp + i, val);
		for (size_type i = pos + n; i < this->length; i++)
			allocator.construct(tmp + i, *(this->first + i - n));
		allocator.deallocate(this->first, old_capacity);
		this->first = tmp;
	}
	else if (this->length > this->capacityAllocated)
	{
		this->capacityAllocated *= 2;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = n;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < pos; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = pos; i < pos + n; i++)
			allocator.construct(tmp + i, val);
		for (size_type i = pos + n; i < this->length; i++)
			allocator.construct(tmp + i, *(this->first + i - n));
		allocator.deallocate(this->first, old_capacity);
		this->first = tmp;
	}
	else
	{
		for (size_type i = this->length - 1; i >= pos + n; i--)
			allocator.construct(this->first + i, *(this->first + i - n));
		for (size_type i = pos + n; i > pos; i--)
			allocator.construct(this->first + i - 1, val);
	}
}


template <class T, class Allocator>
template <class InputIterator>
void ft::vector<T, Allocator>::insert (typename ft::vector<T,Allocator>::iterator position, typename ft::enable_if<!ft::is_integral_const<InputIterator>::value, InputIterator>::type first, InputIterator last)
{
	size_type n = std::distance(first, last);
	size_type pos = std::distance(this->begin(), position);
	size_type old_capacity = this->capacityAllocated;
	this->length += n;
	if (this->length > this->capacityAllocated * 2)
	{
		size_type index = 0;
		this->capacityAllocated = this->length;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = n;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < pos; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = pos; i < pos + n; i++)
			allocator.construct(tmp + i, *(first + index++));
		for (size_type i = pos + n; i < this->length; i++)
			allocator.construct(tmp + i, *(this->first + i - n));
		allocator.deallocate(this->first, old_capacity);
		this->first = tmp;
	}
	else if (this->length > this->capacityAllocated)
	{
		size_type index = 0;
		this->capacityAllocated *= 2;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = n;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < pos; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = pos; i < pos + n; i++)
			allocator.construct(tmp + i, *(first + index++));
		for (size_type i = pos + n; i < this->length; i++)
			allocator.construct(tmp + i, *(this->first + i - n));
		allocator.deallocate(this->first, old_capacity);
		this->first = tmp;
	}
	else
	{
		size_type index = n - 1;
		for (size_type i = this->length - 1; i >= pos + n; i--)
			allocator.construct(this->first + i, *(this->first + i - n));
		for (size_type i = pos + n; i > pos; i--)
			allocator.construct(this->first + i - 1, *(first + index--));
	}
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::reserve(size_type new_cap)
{
	if (new_cap < this->capacityAllocated)
		return;
	pointer tmp = allocator.allocate(new_cap);
	for (size_type i = 0; i < this->length; i++)
		allocator.construct(tmp + i, *(this->first + i));
	if (this->first)
	{
		for (size_type i = 0; i < this->length; i++)
			allocator.destroy(this->first + i);
		allocator.deallocate(this->first, this->capacityAllocated);
	}
	this->capacityAllocated = new_cap;
	this->first = tmp;
}

template <class T, class Allocator>
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator = (const ft::vector<T, Allocator>& x)
{
	if (this != &x)
	{
		if (this->first != 0)
			this->clear();
		for (size_type i = 0; i < this->length; i++)
			allocator.destroy(this->first + i);
		allocator = x.allocator;
		allocator.deallocate(this->capacityAllocated);
		this->length = x.length;
		this->capacityAllocated = x.capacityAllocated;
		this->first = this->allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < this->length; i++)
			allocator.allocate(this->first + i, *(x.first + i));
	}
	return *this;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T,Allocator>::operator [] (typename ft::vector<T, Allocator>::size_type pos)
{
	return (*(this->first + pos));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T,Allocator>::operator [] (typename ft::vector<T, Allocator>::size_type pos) const
{
	return (*(this->first + pos));
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::pop_back()
{
	erase(this->end() - 1);
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::push_back(const T& value)
{
	if (++this->length > this->capacityAllocated)
	{
		this->capacityAllocated *= 2;
		if (this->capacityAllocated == 0)
			this->capacityAllocated = 1;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < this->length - 1; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (pointer it = this->first; it != this->first + this->length; it++)
			allocator.destroy(it);
		allocator.deallocate(this->first, length - 1);
		this->first = tmp;
		*(this->first + length - 1) = value;
	}
	else
		allocator.construct(this->first + this->length - 1, value);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rbegin()
{
	return (reverse_iterator(this->first + this->length));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::rbegin() const
{
	return (const_reverse_iterator(this->first + this->length));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rend()
{
	return (reverse_iterator(this->first));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::rend() const
{
	return (const_reverse_iterator(this->first));
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::resize(size_type n, value_type val)
{
	if (n > max_size())
		throw std::length_error("vector");
	size_type old_len = this->length;
	size_type old_capacity = this->capacityAllocated;
	this->length = n;
	if (old_len > n)
	{
		for (size_type i = old_len; i > n; i--)
			allocator.destroy(this->first + i);
	}
	if (n > this->capacityAllocated)
	{
		this->capacityAllocated *= 2;
		if (n > this->capacityAllocated)
			this->capacityAllocated = n;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < old_len; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (size_type i = old_len; i < n; i++)
			allocator.construct(tmp + i, val);
		for (size_type i = 0; i < old_len; i++)
			allocator.destroy(this->first + i);
		allocator.deallocate(this->first, old_capacity);
		this->first = tmp;
	}
	else if (n > old_len)
	{
		for (size_type i = old_len; i < n; i++)
			allocator.destroy(this->first + i);
		for (size_type i = old_len; i < n; i++)
			allocator.construct(this->first + i, val);
	}
}

template <class T, class Allocator>
void ft::vector<T, Allocator>::swap (vector& x)
{
	std::swap(this->first, x.first);
	std::swap(this->length, x.length);
	std::swap(this->capacityAllocated, x.capacityAllocated);
	std::swap(this->allocator, x.allocator);
}

// NON MEMBER FUNCTIONS

template <class T, class Alloc>
void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator< (const ft::vector<T,Alloc>& a, const ft::vector<T,Alloc>& b)
{
	return ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return rhs < lhs;
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs < rhs); 
}

}

#endif
