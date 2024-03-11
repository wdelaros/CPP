#include "Base.hpp"


Base::~Base() {

}

Base * generate(void) {
	srand(time(NULL));
	switch (rand() % 3) {
		case 0: 
			return (new A);
		case 1: 
			return (new B);
		default: 
			return (new C);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}