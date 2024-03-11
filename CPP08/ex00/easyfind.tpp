template <typename T> 
typename T::const_iterator easyfind(const T arg, int number) {
	std::vector<int>::const_iterator it;
	it = std::find(arg.begin(), arg.end(), number);
	if (it == arg.end())
		throw std::invalid_argument("no occurence");
	return it;
}
