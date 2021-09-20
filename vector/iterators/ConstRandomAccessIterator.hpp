#ifndef CONSTRANDOMACCESSITERATOR_HPP
#define CONSTRANDOMACCESSITERATOR_HPP

#include <iostream>
#include "RandomAccessIterator.hpp"

namespace ft
{

template <class T>
class ConstRandomAccessIterator
{
	public:
		typedef	const T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

		const T* ptr;

		ConstRandomAccessIterator();
		~ConstRandomAccessIterator();
		ConstRandomAccessIterator(const T *ptr);
		ConstRandomAccessIterator(const ConstRandomAccessIterator& ref);
		ConstRandomAccessIterator(const RandomAccessIterator<T>& ref);

		ConstRandomAccessIterator& operator = (const ConstRandomAccessIterator& ref);

		const T& operator*() const;
		const T* operator->() const;

		bool operator < (const ConstRandomAccessIterator& ref);
		bool operator <= (const ConstRandomAccessIterator& ref);
		bool operator > (const ConstRandomAccessIterator& ref);
		bool operator >= (const ConstRandomAccessIterator& ref);
		bool operator == (const ConstRandomAccessIterator& ref) const;
		bool operator != (const ConstRandomAccessIterator& ref) const;

		ConstRandomAccessIterator& operator += (difference_type);
		ConstRandomAccessIterator& operator -= (difference_type);

		ConstRandomAccessIterator operator + (difference_type) const;
		ConstRandomAccessIterator operator - (difference_type) const;
		ConstRandomAccessIterator& operator ++ ();
		ConstRandomAccessIterator& operator -- ();
		ConstRandomAccessIterator operator ++ (int);
		ConstRandomAccessIterator operator -- (int);

};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator()
{
	this->ptr = 0;
};

template <class T>
ConstRandomAccessIterator<T>::~ConstRandomAccessIterator(){};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator(const T *ptr)
{
	this->ptr = ptr;
};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator(const RandomAccessIterator<T> &src)
{
	this->ptr = src.ptr;
};

template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator = (const ConstRandomAccessIterator<T>& ref)
{
	if (this != &ref)
	{
		*this = ref;
	}
	return (*this);
}

template <class T>
const T& ConstRandomAccessIterator<T>::operator * () const
{
	return *ptr;
}

template <class T>
const T* ConstRandomAccessIterator<T>::operator -> () const
{
	return ptr;
}

template <class T>
bool ConstRandomAccessIterator<T>::operator < (const ConstRandomAccessIterator& ref)
{
	return (this->ptr < ref.ptr);
}

template <class T>
bool ConstRandomAccessIterator<T>::operator <= (const ConstRandomAccessIterator& ref)
{
	return (this->ptr < ref.ptr);
}

template <class T>
bool ConstRandomAccessIterator<T>::operator > (const ConstRandomAccessIterator& ref)
{
	return (this->ptr > ref.ptr);
}

template <class T>
bool ConstRandomAccessIterator<T>::operator >= (const ConstRandomAccessIterator& ref)
{
	return (this->ptr > ref.ptr);
}

template <class T>
bool ConstRandomAccessIterator<T>::operator == (const ConstRandomAccessIterator& ref) const
{
	return (this->ptr == ref.ptr);
}

template <class T>
bool ConstRandomAccessIterator<T>::operator != (const ConstRandomAccessIterator& ref) const
{
	return (this->ptr != ref.ptr);
}
template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator += (difference_type n)
{
	ptr += n;
	return *this;
}

template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator -= (difference_type n)
{
	ptr -= n;
	return *this;
}

template <class T>
ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator + (difference_type n) const
{
	ConstRandomAccessIterator<T> tmp = *this;
	tmp += n;
	return (tmp);
}

template <class T>
ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator - (difference_type n) const
{
	ConstRandomAccessIterator<T> tmp = *this;
	tmp -= n;
	return (tmp);
}

template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator ++ ()
{
	this->ptr++;
	return (*this);
}

template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator -- ()
{
	this->ptr--;
	return (*this);
}

template <class T>
ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator ++ (int)
{
	ConstRandomAccessIterator<T> tmp = *this;
	++(this->ptr);
	return tmp;
}

template <class T>
ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator -- (int)
{
	ConstRandomAccessIterator<T> tmp = *this;
	--(this->ptr);
	return tmp;
}

}

#endif
