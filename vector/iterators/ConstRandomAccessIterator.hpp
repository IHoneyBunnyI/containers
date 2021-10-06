#ifndef CONSTRANDOMACCESSITERATOR_HPP
#define CONSTRANDOMACCESSITERATOR_HPP

#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"

namespace ft
{
template <class T>
class RandomAccessIterator;


template <class T>
class ConstRandomAccessIterator
{
	private:
		T* ptr;
	public:
		typedef const T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;


		ConstRandomAccessIterator();
		~ConstRandomAccessIterator();
		ConstRandomAccessIterator(T *ptr);
		ConstRandomAccessIterator(const ConstRandomAccessIterator& ref);
		ConstRandomAccessIterator(const RandomAccessIterator<T>& ref);

		ConstRandomAccessIterator& operator = (const ConstRandomAccessIterator& ref);

		reference operator*() const;
		pointer operator->() const;

		bool operator < (const ConstRandomAccessIterator<T>& ref);
		bool operator < (const RandomAccessIterator<T>& ref);

		bool operator <= (const ConstRandomAccessIterator<T>& ref);
		bool operator <= (const RandomAccessIterator<T>& ref);

		bool operator > (const ConstRandomAccessIterator<T>& ref);
		bool operator > (const RandomAccessIterator<T>& ref);

		bool operator >= (const ConstRandomAccessIterator<T>& ref);
		bool operator >= (const RandomAccessIterator<T>& ref);

		bool operator == (const ConstRandomAccessIterator<T>& ref) const;
		bool operator == (const RandomAccessIterator<T>& ref) const;

		bool operator != (const ConstRandomAccessIterator<T>& ref) const;
		bool operator != (const RandomAccessIterator<T>& ref) const;

		ConstRandomAccessIterator& operator += (difference_type);
		ConstRandomAccessIterator& operator -= (difference_type);

		ConstRandomAccessIterator operator + (difference_type) const;
		ConstRandomAccessIterator operator - (difference_type) const;
		difference_type operator - (const ConstRandomAccessIterator<T>& n) const;
		difference_type operator - (const RandomAccessIterator<T>& n) const;
		ConstRandomAccessIterator& operator ++ ();
		ConstRandomAccessIterator& operator -- ();
		ConstRandomAccessIterator operator ++ (int);
		ConstRandomAccessIterator operator -- (int);
		reference operator[](difference_type index);
		pointer get_ptr() const;

		template <class type>
		friend ConstRandomAccessIterator<type> operator + (typename ConstRandomAccessIterator<type>::difference_type n, const ConstRandomAccessIterator<type>& ref);

};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator()
{
	this->ptr = 0;
};

template <class T>
ConstRandomAccessIterator<T>::~ConstRandomAccessIterator(){};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator(T *ptr)
{
	this->ptr = ptr;
};

template <class T>
ConstRandomAccessIterator<T>& ConstRandomAccessIterator<T>::operator = (const ConstRandomAccessIterator<T>& ref)
{
	if (this != &ref)
	{
		this->ptr = ref.ptr;
	}
	return (*this);
}

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator(const RandomAccessIterator<T> &src)
{
	this->ptr = src.get_ptr();
};

template <class T>
ConstRandomAccessIterator<T>::ConstRandomAccessIterator(const ConstRandomAccessIterator<T>&src)
{
	*this = src;
};

template <class T>
typename ft::ConstRandomAccessIterator<T>::reference ConstRandomAccessIterator<T>::operator * () const
{
	return *(this->ptr);
}

template <class T>
typename ft::ConstRandomAccessIterator<T>::pointer ConstRandomAccessIterator<T>::operator -> () const
{
	return ptr;
}

template <class T>
bool ConstRandomAccessIterator<T>::operator < (const ConstRandomAccessIterator<T>& ref)
{
	return (this->ptr < ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator < (const RandomAccessIterator<T>& ref)
{
	return (this->ptr < ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator <= (const ConstRandomAccessIterator<T>& ref)
{
	return (this->ptr <= ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator <= (const RandomAccessIterator<T>& ref)
{
	return (this->ptr <= ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator > (const ConstRandomAccessIterator<T>& ref)
{
	return (this->ptr > ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator > (const RandomAccessIterator<T>& ref)
{
	return (this->ptr > ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator >= (const ConstRandomAccessIterator<T>& ref)
{
	return (this->ptr >= ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator >= (const RandomAccessIterator<T>& ref)
{
	return (this->ptr >= ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator == (const ConstRandomAccessIterator<T>& ref) const
{
	return (this->ptr == ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator == (const RandomAccessIterator<T>& ref) const
{
	return (this->ptr == ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator != (const ConstRandomAccessIterator<T>& ref) const
{
	return (this->ptr != ref.get_ptr());
}

template <class T>
bool ConstRandomAccessIterator<T>::operator != (const RandomAccessIterator<T>& ref) const
{
	return (this->ptr != ref.get_ptr());
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
	return tmp -= n;
}

template <class T>
typename ConstRandomAccessIterator<T>::difference_type ConstRandomAccessIterator<T>::operator - (const ConstRandomAccessIterator<T>& ref) const
{
	return this->ptr - ref.get_ptr();
}

template <class T>
typename ConstRandomAccessIterator<T>::difference_type ConstRandomAccessIterator<T>::operator - (const RandomAccessIterator<T>& ref) const
{
	return this->ptr - ref.get_ptr();
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

template <class T>
typename ConstRandomAccessIterator<T>::reference ConstRandomAccessIterator<T>::operator[](typename ConstRandomAccessIterator<T>::difference_type index)
{
	return (*(this->ptr + index));
}

template <class T>
typename ConstRandomAccessIterator<T>::pointer ft::ConstRandomAccessIterator<T>::get_ptr() const
{
	return this->ptr;
}

template <class type>
ConstRandomAccessIterator<type> operator + (typename ConstRandomAccessIterator<type>::difference_type n, const ConstRandomAccessIterator<type>& ref)
{
	return (ref.get_ptr() + n);
}

}
#endif
