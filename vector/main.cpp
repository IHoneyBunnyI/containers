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

template <class T>
void print_vector(const std::vector<T> &v)
{
	typename std::vector<T>::const_iterator begin = v.begin();
	typename std::vector<T>::const_iterator end = v.end();
	std::cout << "capacity=\t" << v.capacity() << std::endl;
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

void test_iterators()
{
	//Test Iterators
	std::vector<int> a(5, 10);
	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();
	std::vector<int>::const_iterator cbegin = a.begin();
	std::vector<int>::const_iterator cend = a.end();
	std::cout << *(begin + 1) << std::endl; // 1
	std::cout << *(1 + begin) << std::endl; // 2
	std::cout << *(begin - 0) << std::endl; // 3
	std::cout << begin - end << std::endl; // 4
	std::cout << begin - cend << std::endl; //5
	std::cout << end - begin << std::endl; //6
	std::cout << end - cbegin << std::endl; //7
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << *begin << std::endl; // 8
	std::cout << *cbegin << std::endl; // 9
	std::cout << *end << std::endl; // 10
	std::cout << *cend << std::endl; // 11
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
	std::cout << *(begin += 1) << std::endl; //12
	std::cout << *(cbegin += 1) << std::endl; //13
	std::cout << *(begin -= 1) << std::endl; //14
	std::cout << *(cbegin -= 1) << std::endl; //15

	std::cout << *begin << std::endl; //16
	std::cout << *cbegin << std::endl; //17
	std::cout << *end << std::endl; //18
	std::cout << *cend << std::endl; //19

	std::cout << (begin != cbegin) << std::endl; //20
	std::cout << (begin != begin) << std::endl; //21
	std::cout << (begin == cbegin) << std::endl; //22
	std::cout << (begin == begin) << std::endl; //23

	std::cout << (begin < cbegin) << std::endl; //24
	std::cout << (begin < begin) << std::endl; //25
	std::cout << (begin <= cbegin) << std::endl; //26
	std::cout << (begin <= begin) << std::endl; //27

	std::cout << (begin > cbegin) << std::endl; //28
	std::cout << (begin > begin) << std::endl; //29
	std::cout << (begin >= cbegin) << std::endl; //30
	std::cout << (begin >= begin) << std::endl; //31

	std::cout << begin[0] << std::endl; //32
	std::cout << cbegin[0] << std::endl; //33
	std::cout << end[0] << std::endl; //34
	std::cout << cend[0] << std::endl; //35

	std::vector<class B> b(5);
	std::vector<class B>::iterator bbegin = b.begin();
	std::vector<class B>::const_iterator cbbegin = b.begin();

	std::cout << bbegin->a << bbegin->b << std::endl; //36
	std::cout << (*bbegin).a << (*bbegin).b << std::endl; //37

	std::cout << cbbegin->a << cbbegin->b << std::endl; //38
	std::cout << (*cbbegin).a << (*cbbegin).b << std::endl; //39

	cbegin = begin;
	//*cbegin = *begin;
	//*cbegin = 10;
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

void test_push_back()
{
	std::vector<int> a;
	a.push_back(1);
	print_vector(a);
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

void test_back()
{
	std::vector<int> a(10, 10);
	print_vector(a);
	std::cout << "back = \033[38;5;57m" << a.back() << "\033[0m" <<std::endl;
	a.push_back(99);
	print_vector(a);
	std::cout << "back = \033[38;5;57m" << a.back() << "\033[0m" <<std::endl;

	const std::vector<int> a_c(10, 99);
	print_vector(a_c);
	std::cout << "back = \033[38;5;57m" << a_c.back() << "\033[0m" <<std::endl;
}

void test_erase()
{
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	//std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin() + 1);
	//std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.end() - 1);
	//std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin() + 3);
	//std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	for (int i = 0; i < 100; i++)
		a.push_back(i);
	print_vector(a);
	a.erase(a.begin(), a.begin() + 20);
	print_vector(a);
	a.erase(a.end() - 40, a.end() - 1);
	print_vector(a);
}

void test_front()
{
	std::vector<int> a;
	a.push_back(1);
	std::cout << a.front() << std::endl;
	a.front() += 10;
	std::cout << a.front() << std::endl;
	a.front() -= 100;
	std::cout << a.front() << std::endl;
	a.push_back(1);
	std::cout << a.front() << std::endl;
}

void test_get_allocator()
{

	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	print_vector(myvector);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';
	print_vector(myvector);

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void test_pop_back()
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

int main()
{
	test_iterators();
	test_clear();
	test_million_push_back();
	test_push_back();
	test_assign();
	test_at();
	test_back();
	test_erase();
	test_front();
	test_get_allocator();
	test_pop_back();
	//while (1);
}
