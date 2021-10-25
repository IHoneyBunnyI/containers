#include <iostream>
#include "Stack.hpp"
#include <stack>
typedef std::size_t				size_type;

template <class T>
void print_stack(ft::stack<T> &s)
{
	std::cout << "\e[38;5;220m" << "is empty?:\t\t" << s.empty() << "\e[0m" << std::endl;
	std::cout << "\e[38;5;125m" << "size=\t\t\t" << s.size() << "\e[0m" << std::endl;
	if (!(s.empty()))
	{
		std::cout << "top= \033[38;5;46m" << s.top() << "\033[0m ";
		std::cout << std::endl;
	}
}

template <class T>
void print_stack(const ft::stack<T> &s)
{
	std::cout << "is empty?:\t\t" << s.empty() << std::endl;
	std::cout << "size=\t\t" << s.size() << std::endl;
	if (!(s.empty()))
	{
		std::cout << "top= \033[38;5;46m" << s.top() << "\033[0m ";
		std::cout << std::endl;
	}
}

int main()
{
	ft::stack<int> stack;
	print_stack(stack);
	stack.push(10);
	print_stack(stack);
	for (int i = 0; i < 10000000; i++)
		stack.push(i + 1);
	print_stack(stack);
	for (size_type i = 0; i < stack.size(); i++)
		stack.pop();
	print_stack(stack);

	ft::stack<int> stack2;
	ft::stack<int> stack3;
	std::cout << "== " << (stack2 == stack3) << std::endl;
	std::cout << "== " <<  (stack == stack3) << std::endl;
	std::cout << "== " <<  (stack == stack3) << std::endl;

	std::cout << "!= " <<  (stack2 != stack3) << std::endl;
	std::cout << "!= " <<  (stack != stack3) << std::endl;
	std::cout << "!= " <<  (stack != stack3) << std::endl;

	std::cout << "< " <<  (stack2 < stack3) << std::endl;
	std::cout << "< " <<  (stack < stack3) << std::endl;
	std::cout << "< " <<  (stack < stack3) << std::endl;

	std::cout << "<= " <<  (stack2 <= stack3) << std::endl;
	std::cout << "<= " <<  (stack <= stack3) << std::endl;
	std::cout << "<= " <<  (stack <= stack3) << std::endl;

	std::cout << "> " <<  (stack2 > stack3) << std::endl;
	std::cout << "> " <<  (stack > stack3) << std::endl;
	std::cout << "> " <<  (stack > stack3) << std::endl;

	std::cout << ">= " <<  (stack2 >= stack3) << std::endl;
	std::cout << ">= " <<  (stack >= stack3) << std::endl;
	std::cout << ">= " <<  (stack >= stack3) << std::endl;
	//while(1);
}
