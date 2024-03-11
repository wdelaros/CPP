#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(const Span& inst) {
	*this = inst;
}

Span::~Span() {

}

Span& Span::operator=(const Span& inst) {
	this->_vec = inst._vec;
	this->_n = inst._n;
	return *this;
}

void Span::addNumber(int number) {
	if (_vec.size() >= _n)
		throw std::invalid_argument("too many number");
	_vec.push_back(number);
}

void Span::addRange(int range, int startNumber) {
	if (_vec.size() + range > _n)
		throw std::invalid_argument("too many number");
	int size = _vec.size();
	_vec.resize(_vec.size() + range, 0);
	iota(_vec.begin() + size, _vec.end(), startNumber);
}

unsigned int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw std::invalid_argument("need 2 number or more");
	unsigned int dist = std::abs(_vec[0] - _vec[1]);
	for (size_t i = 0; _vec.size() - 1 > i; i++) {
		for (size_t j = i + 1; _vec.size() > j; j++) {
			unsigned int absDist = std::abs(_vec[i] - _vec[j]);
			if (absDist < dist)
				dist = absDist;
		}
	}
	return dist;
}

unsigned int Span::longestSpan() {
	if (_vec.size() < 2)
		throw std::invalid_argument("need 2 number or more");
	unsigned int min = *std::min_element(_vec.begin(), _vec.end());
	unsigned int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}
