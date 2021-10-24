#include <iostream>
#include <vector>
#include <map>
#include "Map.hpp"
#include "Vector.hpp"

class B
{
	public:
		std::string a;
		std::string b;
		char *str;
		B()
		{
			a = "Hello";
			b = ", World!";
		}
};

template <class T1, class T2>
void print_map(ft::map<T1, T2> &v)
{
	typename ft::map<T1, T2>::iterator begin = v.begin();
	typename ft::map<T1, T2>::iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

template <class T1, class T2>
void print_map(const ft::map<T1, T2> &v)
{
	typename ft::map<T1, T2>::const_iterator begin = v.begin();
	typename ft::map<T1, T2>::const_iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

void test_constructors()
{
	ft::map<int, int> one;
	print_map(one);
	one[0] = 0;
	one[1] = 1;
	one[2] = 3;
	one[100] = 100;
	one[3] = 3;
	print_map(one);

	ft::map<int, int> two(one);
	print_map(two);
	std::cout << (one == two) << std::endl;
	std::vector<ft::pair<int, int> > vector;
	for (int i = 0; i < 100; i++)
		vector.push_back(ft::pair<int, int>(i, i));
	std::vector<ft::pair<int, int> >::iterator begin = vector.begin();
	std::vector<ft::pair<int, int> >::iterator end = vector.end();
	ft::map<int, int> three(begin, end);
	print_map(three);
}

int main()
{
	std::vector<int> a;
	test_constructors();
}
