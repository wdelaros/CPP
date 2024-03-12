#pragma once

#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack():std::stack<T>() {}
		MutantStack(const MutantStack<T>& inst) {
			*this = inst;
		}
		~MutantStack() {}

		MutantStack<T>& operator=(const MutantStack<T>& inst) {
			std::stack<T>::operator=(inst);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}
};