#include <iostream>
#include "Stack.hpp"
#include <stack>

template <class T>
void print_stack(std::stack<T> &s)
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
void print_stack(const std::stack<T> &s)
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
	std::stack<int> stack;
	print_stack(stack);
}
