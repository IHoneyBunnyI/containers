#include <iostream>
#include <utility>
#include "RedBlackTree.hpp"
#include "pair.hpp"
#include "pair_first.hpp"
#include "Vector.hpp"

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

	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> > tree;
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<char> >::iterator it = tree.begin();
	tree.insert(it, ft::pair<int, int>(0, 333));
	tree.insert(it, ft::pair<int, int>(18, 401));
	tree.insert(it, ft::pair<int, int>(9, 30));
	tree.insert(it, ft::pair<int, int>(10, 55));
	tree.insert(it, ft::pair<int, int>(5, 30));
	tree.insert(it, ft::pair<int, int>(14, 45456));
	tree.insert(it, ft::pair<int, int>(7, 3));
	tree.insert(it, ft::pair<int, int>(30, 0));
	tree.insert(it, ft::pair<int, int>(15, 99));
	tree.insert(it, ft::pair<int, int>(28, 5000));

	tree.printTree();
	std::cout << "tree contains: " << std::endl;
	for (it = tree.begin(); it != tree.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;

	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> > tree2(tree);
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<char> >::iterator it2 = tree2.begin();
	std::cout << std::endl;
	std::cout << std::endl;
	tree2.printTree();

	std::cout << "tree contains: " << std::endl;
	for (; it2 != tree2.end(); ++it2)
		std::cout << it2->first << " => " << it2->second << std::endl;
	ft::vector<ft::pair<int, int> > vector;
	for (int i = 1; i < 30; i++)
		vector.push_back(ft::pair<int, int>(i, i + 100));
	ft::RedBlackTree<int, ft::pair<int, int>, pair_first<ft::pair<int, int> >, std::less<int> > tree_vector;
	ft::vector<ft::pair<int, int> >::iterator it_vector = vector.begin();
	ft::vector<ft::pair<int, int> >::iterator it_vector_end = vector.end();
	tree_vector.insert(it_vector, it_vector_end);

	tree_vector.printTree();
	//while (1);
}
