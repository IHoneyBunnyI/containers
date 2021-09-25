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
void print_vector(std::vector<T> &v)
{
	typename std::vector<T>::iterator begin = v.begin();
	typename std::vector<T>::iterator end = v.end();
	std::cout << "capacity=\t" << v.capacity() << std::endl;
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

void test_clear()
{
	{
		std::vector<int> a(4, 10);
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
		a.clear();
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
	}
	{
		std::vector<int> a(10, 100);
		std::vector<int>::iterator begin = a.begin();
		std::vector<int>::iterator end = a.end();
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
	std::vector<int> c;
	c.clear();
	std::cout << c.max_size() << std::endl;
}

void test_million_push_back()
{
	std::vector<int> a(10);
	for (int i = 0; i < 1000000; i++)
		a.push_back(1000);
}

void test_assign()
{
	//with_iterators
	std::vector<int> a(15, 1);
	std::vector<int> b(10, 9);
	print_vector(b);
	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();
	std::vector<int>::iterator cbegin = a.begin();
	std::vector<int>::iterator cend = a.end();
	b.assign(begin, end);
	b.assign(cbegin, cend);
	print_vector(b);
	std::vector<int> c;
	std::vector<int>::iterator begin1 = c.begin();
	std::vector<int>::iterator end1 = c.end();
	b.assign(begin1, end1);
	print_vector(b);
	a.assign(a.begin(), a.end());
	print_vector(a);
	std::vector<int> aa;
	std::vector<int>::iterator begin2 = aa.begin();
	std::vector<int>::iterator end2 = aa.end();
	aa.assign(begin2, end2);
	//with value
	std::vector<int> u(15, 1);
	print_vector(u);
	u.assign(20, 4);
	print_vector(u);
	u.assign(50, 10);
	print_vector(u);
	u.assign(0, 1);
	print_vector(u);
}

void test_at()
{
	int a_ref;
	int a_ref2;
	std::vector<int> a(10, 4);
	try
	{
		a_ref = a.at(9);
		a_ref2 = a.at(10);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a_ref << std::endl;
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

int main()
{
	//test_clear();
	//test_million_push_back();
	//test_assign();
	//test_at();
	//while (1);
}
