#pragma once
#include <iostream>

template <typename T>
T a(T array) {
	return array + 1;
}

template <typename T>
void iter(T *array, int len, T function(T arg)) {
	for (int i = 0; i < len; i++) {
		array[i] = function(array[i]);
	}
}

template <typename T, typename PTRF>
void iter(T *array, int len, PTRF function) {
	for (int i = 0; i < len; i++) {
		function(array[i]);
	}
}