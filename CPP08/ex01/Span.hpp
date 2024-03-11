#pragma once

#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include <stdexcept>

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_n;

	public:
		Span(unsigned int n);
		Span(const Span& inst);
		~Span();

		Span&	operator=(const Span& inst);

		void			addNumber(int number);
		void			addRange(int range, int startNumber);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};