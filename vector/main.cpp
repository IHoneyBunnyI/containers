#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::vector<int> vec1(10, 110);
	std::vector<int> v(4, 10);
	std::vector<int>::iterator begin = v.begin();
	std::vector<int>::iterator end = v.end();
	ft::vector<int> aaaa(begin, end);
}
