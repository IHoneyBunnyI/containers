#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::vector<int> vec;
	vec.push_back(10);
	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::const_iterator it1 = vec.begin();
	//std::cout << *it << std::endl;
	std::cout << *it1 << std::endl;
}
