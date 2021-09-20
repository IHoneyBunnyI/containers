#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "RandomAccessIterator.hpp"
#include "ConstRandomAccessIterator.hpp"
#include "ReverseRandomAccessIterator.hpp"
#include "ConstReverseRandomAccessIterator.hpp"


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
		T* first;
		T* last;
		value_type* arr;
		size_type capacity;
		size_type length;
		Allocator allocator;

	public:

		vector() : first(0), last(0), capacity(0), length(0) {}


		const_iterator begin() const
		{
			return const_iterator(first);
		}
		iterator begin()
		{
			return iterator(first);
		}

		void push_back(const value_type& value);

};

template <class T, class Allocator>
void ft::vector<T, Allocator>::push_back(const value_type& value)
{
	if (capacity == 0 && length == 0)
	{
		capacity++;
		length++;
		arr = allocator.allocate(sizeof(value_type));
		arr[0] = value;
		first = &arr[0];
	}
	//if (++length >= capacity)
	//{

		//allocator.dealocate(arr);
	//}
	
}

}

#endif
