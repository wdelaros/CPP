#pragma once

# include <chrono>
# include <ctime>
# include <vector>
# include <deque>
# include <iomanip> 
# include <iostream>

bool	parseArgument(int argc, char *argv[]);
void	print(int argc, char *argv[]);
void	print(std::chrono::duration<double> timer, int argc, std::string str);

template<typename T>
static void insertionSort(T& container, int start, int range) {
	for (int i = start; i < range; i++) {
		int tempVal = container[i + 1];
		int j = i + 1;
		while (j > start && container[j - 1] > tempVal) {
			container[j] = container[j - 1];
			j--;
		}
		container[j] = tempVal;
	}
}

template<typename T>
static void merge(T& container, int start, int range, int end) {
	int n1 = range - start + 1;
	int n2 = end - range;
	T LA(container.begin() + start, container.begin() + range + 1);
	T RA(container.begin() + range + 1, container.begin() + end + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = start; i < end - start + 1; i++) {
		if (RIDX == n2) {
			container[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			container[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			container[i] = LA[LIDX];
			LIDX++;
		} else {
			container[i] = RA[RIDX];
			RIDX++;
		}
	}
}

template<typename T>
static void sort(T& container, int start, int end, int group) {
	if (end - start > group) {
		int range = (start + end) / 2;
		sort(container, start, range, group);
		sort(container, range + 1, end, group);
		merge(container, start, range, end);
	} else {
		insertionSort(container, start, end);
	}
}

template<typename T>
void	startAlgo(T& container, int argc, char *argv[]) {
	for (int i = 1; i < argc; i++)
		container.push_back(std::atoi(argv[i]));
	
	sort(container, 0, container.size() - 1, container.size() / 2);
}

template<typename T>
void print(T& container) {
	std::cout << "After:	";
	for(size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}