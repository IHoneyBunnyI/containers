#include <iostream>
#include <vector>
#include "Vector.hpp"


class B
{
	public:
		std::string a;
		std::string b;
		B()
		{
			a = "Hello";
			b = ", World!";
		}
};


int main()
{
	//Test Iterators
	std::vector<int> a(4, 10);
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
	a.clear();
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
}
