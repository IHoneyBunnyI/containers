#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T						value_type;
		typedef Container				container_type;
		typedef std::size_t				size_type;
	private:
		container_type c;
	
	public:
		//CONSTRUCTOR
		explicit stack (const container_type& ctnr = container_type());

		//MEMBER FUNCTIONS
		bool empty() const;
		size_type size() const;
		value_type& top();
		const value_type& top() const;
		void push (const value_type& val);
		void pop();

		template <class _T, class _Container>
		friend bool operator== (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs);
		template <class _T, class _Container>
		friend bool operator<  (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs);
};

template <class T, class Container>
ft::stack<T, Container>::stack (const typename ft::stack<T, Container>::container_type& ctnr): c(ctnr) {}

template <class T, class Container>
bool ft::stack<T, Container>::empty() const
{
	if (this->c.empty())
		return true;
	return false;
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
	return c.size();
}

template <class T, class Container>
typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top()
{
	return c.back();
}

template <class T, class Container>
const typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top() const
{
	return c.back();
}
template <class T, class Container>
void ft::stack<T, Container>::push (const ft::stack<T, Container>::value_type& val)
{
	c.push_back(val);
}
template <class T, class Container>
void ft::stack<T, Container>::pop()
{
	c.pop_back();
}

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return lhs.c == rhs.c;
}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return lhs.c < rhs.c;
}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(lhs < rhs);
}

}
#endif
