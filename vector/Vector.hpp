#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "RandomAccessIterator.hpp"
#include "ConstRandomAccessIterator.hpp"
#include "ReverseRandomAccessIterator.hpp"
#include "ConstReverseRandomAccessIterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"


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
		typedef ReverseRandomAccessIterator<value_type>			reverse_iterator;
		typedef ConstReverseRandomAccessIterator<value_type>	const_reverse_iterator;

	private:
		value_type* first;
		value_type* last;
		size_type capacityAllocated;
		size_type length;
		Allocator allocator;

	public: //Construcors
		vector();
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template<class InputIt>
		vector(InputIt first, typename ft::enable_if<!ft::is_integral_const<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator());
		vector(const vector& other);
	public:
		~vector();

	public: //member functions
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();
		bool empty() const;
		size_type size() const;
		size_type max_size() const;//ok
		void reserve(size_type new_cap);//ok
		size_type capacity() const;//ok
		void clear();//ok
		void push_back(const T& value);//ok

		template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		void assign (size_type n, const value_type& val);

		//template<class InputIt>
		//void assign(InputIt first, InputIt last);
		//void assign(size_type count, const T& value);

	public: //operators
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;
};

//=========================Constructors=================================
template <class T, class Allocator>
ft::vector<T, Allocator>::vector() : first(0), last(0), capacityAllocated(0), length(0), allocator(allocator_type()) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc) : first(0), last(0), capacityAllocated(0), length(0), allocator(alloc) {}


template <class T, class Allocator>
ft::vector<T, Allocator>::vector(ft::vector<T, Allocator>::size_type count, const T& value, const Allocator& alloc) : allocator(alloc)
{
	first = allocator.allocate(count);
	this->capacityAllocated = count;
	this->length = count;
	for (size_type i = 0; i < count; i++)
		allocator.construct(first + i, value);
	this->last = this->first + this->length;
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
	this->last = this->first + this->length;
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const vector& other): allocator(other.allocator)
{
	this->length = other.length;
	this->capacityAllocated = other.capacityAllocated;
	this->first = allocator.allocate(this->capacityAllocated);
	for (size_type i = 0; i < this->length; i++)
		allocator.construct(this->first + i, *(other.first + i));
	this->last = this->first + this->length;
}

//=========================Destructor=================================
template <class T, class Allocator>
ft::vector<T, Allocator>::~vector()
{
	if (first != 0)
	{
		for (size_type i = 0; first + i != last; i++)
			allocator.destroy(first + i);
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
	return allocator.max_size(); //////////ПОЛНЫЙ БРЕД
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
void ft::vector<T, Allocator>::push_back(const T& value)
{
	if (this->capacityAllocated == 0)
		this->capacityAllocated = 1;
	if (++length > this->capacityAllocated)
	{
		this->capacityAllocated *= 2;
		pointer tmp = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; i < length - 1; i++)
			allocator.construct(tmp + i, *(this->first + i));
		for (pointer it = this->first; it != this->last; it++)
			allocator.destroy(it);
		allocator.deallocate(this->first, length - 1);
		this->first = tmp;
		*(this->first + length - 1) = value;
		this->last = this->first + length;
	}
	else
	{
		*(this->last) = value;
		this->last = this->first + length;
	}
}

template <class T, class Allocator>
template <class InputIterator>
void ft::vector<T, Allocator>::assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
{
	this->clear();
	//this->insert(this->first, first, last); можно так
	size_type dist = std::distance(first, last);
	if (dist > this->capacityAllocated)
	{
		allocator.deallocate(this->first, this->capacityAllocated);
		this->capacityAllocated = dist;
		this->length = dist;
		this->first = allocator.allocate(this->capacityAllocated);
		for (size_type i = 0; first + i < last; i++)
			allocator.construct(this->first + i, *(first + i));
		this->last = this->first + this->length;
	}
	else
	{
		this->length = dist;
		for (size_type i = 0; first + i < last; i++)
			allocator.construct(this->first + i, *(first + i));
		this->last = this->first + this->length;
	}
}

//=========================Operators=================================
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

}
#endif
