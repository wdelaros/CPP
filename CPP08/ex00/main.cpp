#include "easyfind.hpp"

int main() {
	try {
		std::vector<int> v(5);

		v.push_back(5);
		v.push_back(15);
		v.push_back(25);
		v.push_back(35);
		v.push_back(45);
	
		std::cout << *easyfind(v, 26) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::vector<int> v(5);

		v.push_back(5);
		v.push_back(15);
		v.push_back(25);
		v.push_back(35);
		v.push_back(45);
	
		std::cout << *easyfind(v, 25) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
