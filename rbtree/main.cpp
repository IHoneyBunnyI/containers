#include <iostream>
#include <utility>
#include "RedBlackTree.hpp"
#include "pair.hpp"
#include "pair_first.hpp"

void test_pair_and_make_pair()
{

	int n = 1;
	int a[5] = {1, 2, 3, 4, 5};
 
	// build a pair from two ints
	ft::pair<int, int> p1 = ft::make_pair(n, a[1]);
	std::cout << "The value of p1 is "
			  << "(" << p1.first << ", " << p1.second << ")\n";

	ft::pair<int, int> p2 = ft::make_pair(10, 100);
	std::cout << "The value of p2 is "
			  << "(" << p2.first << ", " << p2.second << ")\n";

	ft::pair<char, double> p3 = ft::make_pair('c', 1.3456);
	std::cout << "The value of p3 is "
			  << "(" << p3.first << ", " << p3.second << ")\n";

	p1 = p2;

	std::cout << "p1 = p2 : ";
	std::cout << "The value of p1 is "
			  << "(" << p1.first << ", " << p1.second << ")\n";

	std::cout << "The value of p2 is "
			  << "(" << p2.first << ", " << p2.second << ")\n";

	std::cout << (p1 == p2) << std::endl;
	std::cout << (p1 != p2) << std::endl;
	std::cout << (p1 < p2) << std::endl;
	std::cout << (p1 <= p2) << std::endl;
	std::cout << (p1 > p2) << std::endl;
	std::cout << (p1 >= p2) << std::endl;
}

int main()
{
	//test_pair_and_make_pair();
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> > a;
	const ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> > b(a);

	//ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::iterator it = a.begin();
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::reverse_iterator rit = a.rbegin();
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::const_reverse_iterator rcit = a.rbegin();
	//(void)it;
	//(void)cit;
	(void)rit;
	(void)rcit;
	//std::cout << a.empty() << " " << b.empty() << std::endl;
	//std::cout << a.size() << " " << b.size() << std::endl;
	ft::pair<int, int> pair (10, 15);
	a.insert(pair);
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::iterator it = a.begin();
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::const_iterator cit = a.begin();
	a.insert(cit, pair);
	std:: cout << it->first << std::endl;
	std:: cout << cit->first << std::endl;
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::iterator start = a.begin();
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> >::iterator last = a.end();
	a.insert(start, last);
	//while (1);
}
