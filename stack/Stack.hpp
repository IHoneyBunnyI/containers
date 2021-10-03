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
		explicit stack (const container_type& ctnr = container_type());
};

template <class T, class Container>
ft::stack<T, Container>::stack (const typename ft::stack<T, Container>::container_type& ctnr): container(ctnr) {}

}
#endif
