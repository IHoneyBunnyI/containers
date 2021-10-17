#include <iostream>
#include <utility>
#include "RedBlackTree.hpp"
#include "pair.hpp"

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
	ft::RedBlackTree<int, char, int, char> a;
	const ft::RedBlackTree<int, char, int, char> b(a);

	ft::RedBlackTree<int, char, int, char>::iterator it = a.begin();
	ft::RedBlackTree<int, char, int, char>::const_iterator cit = a.begin();
	ft::RedBlackTree<int, char, int, char>::reverse_iterator rit = a.rbegin();
	ft::RedBlackTree<int, char, int, char>::const_reverse_iterator rcit = a.rbegin();

	//ft::RedBlackTree<int, char, int, char>::iterator bit = b.begin();
	ft::RedBlackTree<int, char, int, char>::const_iterator bcit = b.begin();
	//ft::RedBlackTree<int, char, int, char>::reverse_iterator brit = b.rbegin();
	ft::RedBlackTree<int, char, int, char>::const_reverse_iterator brcit = b.rbegin();
	(void)it;
	(void)cit;
	(void)rit;
	(void)rcit;
	(void)bcit;
	(void)brcit;
	std::cout << a.empty() << " " << b.empty() << std::endl;
	std::cout << a.size() << " " << b.size() << std::endl;
	//while (1);
}
