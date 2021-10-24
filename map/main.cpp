#include <iostream>
#include <vector>
#include <map>
#include "Map.hpp"
#include "../vector/Vector.hpp"

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
	for (int i = 0; i < 10000; i++)
		vector.push_back(ft::pair<int, int>(i, i));
	std::vector<ft::pair<int, int> >::iterator begin = vector.begin();
	std::vector<ft::pair<int, int> >::iterator end = vector.end();
	ft::map<int, int> three(begin, end);
	print_map(three);

	three = one;
	print_map(three);
}

void test_iterators()
{
	ft::map<int, int> a;
	a[0] = 20;
	a[10] = 40;
	a[1] = 60;
	a[2] = 80;
	a[5] = 100;
	ft::map<int, int>::iterator begin = a.begin();
	ft::map<int, int>::iterator end = a.end();
	ft::map<int, int>::const_iterator cbegin = a.begin();
	ft::map<int, int>::const_iterator cend = a.end();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void test_reverse_iterators()
{
	ft::map<int, int> a;
	a[0] = 20;
	a[10] = 40;
	a[1] = 60;
	a[2] = 80;
	a[5] = 100;
	ft::map<int, int>::reverse_iterator begin = a.rbegin();
	ft::map<int, int>::reverse_iterator end = a.rend();
	ft::map<int, int>::const_reverse_iterator cbegin = a.rbegin();
	ft::map<int, int>::const_reverse_iterator cend = a.rend();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;

	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

int main()
{
	//test_constructors();
	test_iterators();
	test_reverse_iterators();
	//while (1);
}
