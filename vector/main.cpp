#include <iostream>
#include <vector>
#include "Vector.hpp"


class B
{
	public:
		std::string a;
		std::string b;
		B()
		{
			a = "Hello";
			b = ", World!";
		}
};


template <class T>
void print_vector(ft::vector<T> &v)
{
	typename ft::vector<T>::iterator begin = v.begin();
	typename ft::vector<T>::iterator end = v.end();
	std::cout << "capacity=\t" << v.capacity() << std::endl;
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}


int main()
{
	//ft::vector
	{
		ft::vector<int> a(4, 10);
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
		a.clear();
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
	}
	{
		ft::vector<int> a(5, 4);
		a.push_back(10);
		print_vector(a);
		a.push_back(11);
		print_vector(a);
		a.push_back(12);
		print_vector(a);
		a.push_back(10);
		ft::vector<int>::iterator begin = a.begin();
		ft::vector<int>::iterator end = a.end();
		std::cout << end - begin << std::endl;
		print_vector(a);
		a.clear();
		begin = a.begin();
		end = a.end();
		std::cout << a.capacity() << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "\033[31m" << end - begin << "\033[0m" << std::endl;
		print_vector(a);
	}
	ft::vector<int> c;
	c.clear();
	//while (1);
}
