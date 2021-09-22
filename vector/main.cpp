#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	const ft::vector<char> char_vector(100, 'a');
	std::cout << char_vector[99] << std::endl;
}
