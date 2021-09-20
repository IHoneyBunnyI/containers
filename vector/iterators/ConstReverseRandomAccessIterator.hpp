#ifndef CONSTREVERSERANDOMACCESSITERATOR_HPP
#define CONSTREVERSERANDOMACCESSITERATOR_HPP

#include <iostream>

namespace ft
{

template <class T>
class ConstReverseRandomAccessIterator
{
	public:
		typedef	const T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

		const pointer ptr;

		ConstReverseRandomAccessIterator();
		~ConstReverseRandomAccessIterator();
		ConstReverseRandomAccessIterator(T *ptr);
		ConstReverseRandomAccessIterator(const ConstReverseRandomAccessIterator& ref);

		ConstReverseRandomAccessIterator& operator = (const ConstReverseRandomAccessIterator& ref);

		bool operator < (const ConstReverseRandomAccessIterator& ref);
		bool operator <= (const ConstReverseRandomAccessIterator& ref);
		bool operator > (const ConstReverseRandomAccessIterator& ref);
		bool operator >= (const ConstReverseRandomAccessIterator& ref);
		bool operator == (const ConstReverseRandomAccessIterator& ref) const;
		bool operator != (const ConstReverseRandomAccessIterator& ref) const;

		ConstReverseRandomAccessIterator& operator += (difference_type);
		ConstReverseRandomAccessIterator& operator -= (difference_type);

		ConstReverseRandomAccessIterator operator + (difference_type) const;
		ConstReverseRandomAccessIterator operator - (difference_type) const;
		ConstReverseRandomAccessIterator& operator ++ ();
		ConstReverseRandomAccessIterator& operator -- ();
		ConstReverseRandomAccessIterator operator ++ (int);
		ConstReverseRandomAccessIterator operator -- (int);

};
}

#endif
