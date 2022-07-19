#include <iostream>
#include "Set.hpp"
#include <set>
#include <vector>

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

template <class T1>
void print_set(ft::set<T1> &v)
{
	(void)v;
	typename ft::set<T1>::iterator begin = v.begin();
	typename ft::set<T1>::iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

template <class T1>
void print_set(const ft::set<T1> &v)
{
	(void)v;
	typename ft::set<T1>::const_iterator begin = v.begin();
	typename ft::set<T1>::const_iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

void test_constructors()
{
	ft::set<int> one;
	print_set(one);
	one.insert(0);
	one.insert(1);
	one.insert(100);
	one.insert(3);
	print_set(one);

	ft::set<int> two(one);
	print_set(two);
	std::cout << (one == two) << std::endl;
	std::vector<int> vector;
	for (int i = 0; i < 10000; i++)
		vector.push_back(i);
	std::vector<int>::iterator begin = vector.begin();
	std::vector<int>::iterator end = vector.end();
	ft::set<int> three(begin, end);
	print_set(three);

	three = one;
	print_set(three);
}

void test_iterators()
{
	ft::set<int> a;
	a.insert(20);
	a.insert(40);
	a.insert(60);
	a.insert(80);
	a.insert(100);
	ft::set<int>::iterator begin = a.begin();
	ft::set<int>::iterator end = a.end();
	ft::set<int>::const_iterator cbegin = a.begin();
	ft::set<int>::const_iterator cend = a.end();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
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
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void test_reverse_iterators()
{
	ft::set<int> a;
	a.insert(20);
	a.insert(40);
	a.insert(60);
	a.insert(80);
	a.insert(100);
	ft::set<int>::reverse_iterator begin = a.rbegin();
	ft::set<int>::reverse_iterator end = a.rend();
	ft::set<int>::const_reverse_iterator cbegin = a.rbegin();
	ft::set<int>::const_reverse_iterator cend = a.rend();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
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

	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void test_empty()
{
	ft::set<char> a;
	std::cout << a.empty() << std::endl;
	a.insert(1);
	print_set(a);
	std::cout << a.empty() << std::endl;
	a.erase('a');
	std::cout << a.empty() << std::endl;
	ft::set<char> b(a);
	std::cout << b.empty() << std::endl;
	print_set(a);
}

void test_size()
{
	ft::set<char> set;
	std::cout << set.size() << std::endl;
	set.insert(1);
	std::cout << set.size() << std::endl;
	for (char a = 'a'; a <= 'z'; a++)
		set.insert(a);
	std::cout << set.size() << std::endl;
	print_set(set);
	//std::cout << set.max_size() << std::endl;
}


void test_insert1()
{
	ft::set<int> set;
	for (int i = 0; i < 1000000; i++)
		set.insert(i);
	set.insert(10);
	set.insert(10);
	set.insert(0);
	print_set(set);
}

void test_insert2()
{
	ft::set<int> set;
	ft::set<int>::iterator it = set.begin();
	for (int i = 0; i < 1000000; i++)
		set.insert(it, i+1);
	print_set(set);
	ft::set<int>::iterator it2 = set.begin();
	(it2++)++;
	for (int i = 0; i < 1000000; i++)
		set.insert(it2, i+1);
	print_set(set);
	for (int i = 0; i < 1000000; i++)
		set.insert(it2 = set.end(),i+1);
	print_set(set);
}

void test_insert3()
{
	ft::set<int> set;
	for (int i = 0; i < 10000; i++)
		set.insert(i);
	print_set(set);
	ft::set<int>::iterator begin = set.begin();
	ft::set<int>::iterator end = set.end();
	ft::set<int> set2;
	set2.insert(begin, end);
	print_set(set2);

	std::vector<int> vector;
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	std::vector<int>::iterator begin_v = vector.begin();
	std::vector<int>::iterator end_v = vector.end();
	ft::set<int> set3;
	set3.insert(1999);
	set3.insert(begin_v, end_v);
	print_set(set3);
}

void test_erase1()
{
	std::vector<int> vector;
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	std::vector<int >::iterator begin_v = vector.begin();
	std::vector<int >::iterator end_v = vector.end();
	ft::set<int> set;
	set.insert(1999);
	set.insert(begin_v, end_v);
	print_set(set);

	ft::set<int>::iterator last = set.end();
	last--;
	set.erase(set.begin());
	print_set(set);
	set.erase(last);
	print_set(set);
}

void test_erase2()
{
	ft::set<int> set;
	for (int i = 0; i < 10000; i++)
		set.insert(i);
	print_set(set);
	for (int i = 0; i < 10000; i++)
		set.erase(i);
	print_set(set);
}

void test_erase3()
{
	ft::set<int> set;
	for (int i = 0; i < 10000; i++)
		set.insert(i);
	print_set(set);
	ft::set<int>::iterator begin_1 = set.begin();
	ft::set<int>::iterator end_1 = set.end();
	begin_1++;
	end_1--;
	set.erase(begin_1, end_1);
	print_set(set);
}

void test_swap_clear()
{
	ft::set<int> set;
	for (int i = 0; i < 10000; i++)
		set.insert(i);
	print_set(set);
	ft::set<int> set_swap;
	for (int i = 0; i < 10; i++)
		set.insert(i);
	print_set(set_swap);
	set.swap(set_swap);
	print_set(set_swap);
	print_set(set);
	swap(set_swap, set);
	print_set(set_swap);
	print_set(set);
	set.clear();
	set_swap.clear();
	print_set(set_swap);
	print_set(set);
}

void test_key_comp__value_comp()
{
	{
		ft::set<int> myset;
		ft::set<int>::key_compare mycomp = myset.key_comp();
		myset.insert(100);
		myset.insert(200);
		myset.insert(300);
		std::cout << "myset contains:\n";
		char highest = *(myset.rbegin());		 // key value of last element
		ft::set<int>::iterator it = myset.begin();
		do {
			std::cout << *it << '\n';
		} while ( mycomp((*it++), highest) );
		std::cout << '\n';
	}
	{
			ft::set<int> myset;
		ft::set<int>::value_compare mycomp = myset.value_comp();
		for (int i=0; i<=5; i++) myset.insert(i);
		int highest=*myset.rbegin();
		ft::set<int>::iterator it=myset.begin();
		do {
			std::cout << ' ' << *it;
		} while ( mycomp(*(++it),highest) );
		std::cout << '\n';
	}
}

void test_find()
{
	ft::set<char> myset;
	ft::set<char>::iterator it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');

	it = myset.find('a');
	if (it != myset.end())
		myset.erase(it);
	print_set(myset);

	it = myset.find('c');
	if (it != myset.end())
		myset.erase(it);
	print_set(myset);

	it = myset.find('Z');
	if (it != myset.end())
		myset.erase(it);
	print_set(myset);
}

void test_equal_range()
{
	ft::set<char> a;
	ft::set<char>::iterator it;
	a.insert('a');
	a.insert('b');
	a.insert('c');
	ft::pair<ft::set<char>::iterator, ft::set<char>::iterator> ret;
	ret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << std::endl;
	//ret = a.equal_range('d');
	//std::cout << "lower bound points to: ";
	//std::cout << *ret.first << std::endl;
	//std::cout << "upper bound points to: ";
	//std::cout << *ret.second << std::endl;
	ft::pair<ft::set<char,int>::const_iterator,ft::set<char,int>::const_iterator> cret;
	cret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *cret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *cret.second << std::endl;
	//cret = a.equal_range('d');
	//std::cout << "lower bound points to: ";
	//std::cout << *cret.first << std::endl;
	//std::cout << "upper bound points to: ";
	//std::cout << *cret.second << std::endl;
}

void test_upper_lower_bound()
{
	ft::set<char> a;
	ft::set<char>::iterator itlow, itup;
	ft::set<char>::const_iterator citlow, citup;


	a.insert('a');
	a.insert('b');
	a.insert('c');
	a.insert('d');
	a.insert('e');

	itlow = a.lower_bound ('b');
	itup = a.upper_bound ('d');
	std::cout << *itlow << std::endl;
	std::cout << *itup << std::endl;
	citlow = a.lower_bound ('b');
	citup = a.upper_bound ('d');
	std::cout << *citlow << std::endl;
	std::cout << *citup << std::endl;
	print_set(a);
	a.erase(itlow,itup);
	print_set(a);
	itlow = a.lower_bound ('a');
	itup = a.upper_bound ('e');
	a.erase(itlow,itup);
	print_set(a);
}

int main()
{
	test_constructors();
	test_iterators();
	test_reverse_iterators();
	test_empty();
	test_size();
	test_insert1();
	test_insert2();
	test_insert3();
	test_erase1();
	test_erase2();
	test_erase3();
	test_swap_clear();
	test_key_comp__value_comp();
	test_find();
	test_equal_range();
	test_upper_lower_bound();
	//while (1);
}
