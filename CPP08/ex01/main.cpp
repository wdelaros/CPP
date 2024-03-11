#include "Span.hpp"
#include <iostream>

int main()
{
	{
		try {
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Span sp = Span(10000);

			sp.addRange(10000, -10000);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
