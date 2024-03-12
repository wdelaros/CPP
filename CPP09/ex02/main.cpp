#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	std::chrono::steady_clock::time_point t1;
	std::chrono::steady_clock::time_point t2;
	std::vector<int> container;
	std::deque<int> container2;

	if (!parseArgument(argc, argv)) {
		std::cout << "Error: invalid character" << std::endl;
		return 1;
	}

	t1 = std::chrono::steady_clock::now();
	startAlgo(container, argc, argv);
	t2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> timer1 = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);

	t1 = std::chrono::steady_clock::now();
	startAlgo(container2, argc, argv);
	t2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> timer2 = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);

	print(argc, argv);
	print(container);
	print(timer1, argc, "vector");
	print(timer2, argc, "deque");
	return 0;
}