#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "enable_if.hpp"
#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"

namespace ft
{

template <class T>
class RandomAccessIterator
{
	public:
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

		T* ptr;

		RandomAccessIterator();
		~RandomAccessIterator();
		RandomAccessIterator(T *ptr);
		RandomAccessIterator(const RandomAccessIterator& ref);

		RandomAccessIterator& operator = (const RandomAccessIterator& ref);

		T& operator*() const;
		T* operator->() const;

		bool operator < (const RandomAccessIterator<T>& ref);
		bool operator <= (const RandomAccessIterator<T>& ref);
		bool operator > (const RandomAccessIterator<T>& ref);
		bool operator >= (const RandomAccessIterator<T>& ref);
		bool operator == (const RandomAccessIterator<T>& ref) const;
		bool operator != (const RandomAccessIterator<T>& ref) const;

		RandomAccessIterator& operator += (difference_type);
		RandomAccessIterator& operator -= (difference_type);

		RandomAccessIterator operator + (difference_type) const;
		RandomAccessIterator operator - (difference_type) const;
		difference_type operator - (const RandomAccessIterator<T>& n) const;
		RandomAccessIterator& operator ++ ();
		RandomAccessIterator& operator -- ();
		RandomAccessIterator operator ++ (int);
		RandomAccessIterator operator -- (int);

};

template <class T>
RandomAccessIterator<T>::RandomAccessIterator()
{
	this->ptr = 0;
};

template <class T>
RandomAccessIterator<T>::~RandomAccessIterator(){};

template <class T>
RandomAccessIterator<T>::RandomAccessIterator(T *ptr)
{
	this->ptr = ptr;
};

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator = (const RandomAccessIterator<T>& ref)
{
	if (this != &ref)
	{
		this->ptr = ref.ptr;
	}
	return (*this);
}

template <class T>
RandomAccessIterator<T>::RandomAccessIterator(const RandomAccessIterator &src)
{
	*this = src;
};

template <class T>
T& RandomAccessIterator<T>::operator * () const
{
	return *(this->ptr);
}

template <class T>
T* RandomAccessIterator<T>::operator -> () const
{
	return ptr;
}

template <class T>
bool RandomAccessIterator<T>::operator < (const RandomAccessIterator& ref)
{
	return (this->ptr < ref.ptr);
}

template <class T>
bool RandomAccessIterator<T>::operator <= (const RandomAccessIterator& ref)
{
	return (this->ptr < ref.ptr);
}

template <class T>
bool RandomAccessIterator<T>::operator > (const RandomAccessIterator& ref)
{
	return (this->ptr > ref.ptr);
}

template <class T>
bool RandomAccessIterator<T>::operator >= (const RandomAccessIterator& ref)
{
	return (this->ptr > ref.ptr);
}

template <class T>
bool RandomAccessIterator<T>::operator == (const RandomAccessIterator& ref) const
{
	return (this->ptr == ref.ptr);
}

template <class T>
bool RandomAccessIterator<T>::operator != (const RandomAccessIterator& ref) const
{
	return (this->ptr != ref.ptr);
}
template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator += (difference_type n)
{
	ptr += n;
	return *this;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator -= (difference_type n)
{
	ptr -= n;
	return *this;
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator + (difference_type n) const
{
	RandomAccessIterator<T> tmp = *this;
	tmp += n;
	return (tmp);
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator - (difference_type n) const
{
	RandomAccessIterator<T> tmp = *this;
	return tmp -= n;
}

template <class T>
typename RandomAccessIterator<T>::difference_type RandomAccessIterator<T>::operator - (const RandomAccessIterator<T>& ref) const
{
	return this->ptr - ref.ptr;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator ++ ()
{
	this->ptr++;
	return (*this);
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator -- ()
{
	this->ptr--;
	return (*this);
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator ++ (int)
{
	RandomAccessIterator<T> tmp = *this;
	++(this->ptr);
	return tmp;
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator -- (int)
{
	RandomAccessIterator<T> tmp = *this;
	--(this->ptr);
	return tmp;
}

}
#endif
