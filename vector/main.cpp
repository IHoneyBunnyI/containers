#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::vector<int> a(5, 10);
	ft::vector<int>::iterator cbegin = a.begin();
	ft::vector<int>::iterator cend = a.end();
	std::cout << *(2 + cbegin) << std::endl;
	std::cout << *(cbegin + 2) << std::endl;
	(void)cend;
}
