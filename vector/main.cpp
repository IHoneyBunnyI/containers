#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	std::vector<int> a(5, 10);
	std::vector<int>::const_iterator cbegin = a.begin();
	//std::vector<int>::iterator cend = a.end();
	std::cout << *(2 + cbegin) << std::endl;
	std::cout << *(cbegin + 2) << std::endl;
}
