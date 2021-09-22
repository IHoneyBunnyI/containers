#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::vector<int> vec(2, 110);
	ft::vector<int>::iterator it = vec.begin();
	std::cout << *it << std::endl;
	*it = 10;
	std::cout << *it << std::endl;
}
