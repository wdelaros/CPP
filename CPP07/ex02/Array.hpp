#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& inst);
		~Array();

		Array& operator=(const Array& inst);
		T& operator[](int index);
		const T& operator[](int index) const;

		int	size() const;
};

#include "Array.tpp"