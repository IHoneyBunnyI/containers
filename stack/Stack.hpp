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
		container_type container;
	
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
};

template <class T, class Container>
ft::stack<T, Container>::stack (const typename ft::stack<T, Container>::container_type& ctnr): container(ctnr) {}

template <class T, class Container>
bool ft::stack<T, Container>::empty() const
{
	if (this->container.empty())
		return true;
	return false;
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
	return container.size();
}

template <class T, class Container>
typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top()
{
	return container.back();
}

template <class T, class Container>
const typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top() const
{
	return container.back();
}
template <class T, class Container>
void ft::stack<T, Container>::push (const ft::stack<T, Container>::value_type& val)
{
	container.push_back(val);
}
template <class T, class Container>
void ft::stack<T, Container>::pop()
{
	container.pop_back();
}

}
#endif
