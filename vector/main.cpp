#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::vector<int> vector(5, 222);
	ft::vector<int>::iterator std_it = vector.begin();
	ft::vector<int>::iterator std_end = vector.end();
	ft::vector<int> vec(std_it, std_end);

	ft::vector<int>::iterator it = vec.begin();
	std::cout << *it << std::endl;
	*it = 10;
	std::cout << *it << std::endl;
}
