template <typename T>
Array<T>::Array(): _array(NULL), _n(0){
	
}

template <typename T> 
Array<T>::Array(unsigned int n): _array(new T [n]), _n(n) {

}

template <typename T>
Array<T>::Array(const Array& inst){
	*this = inst;
}

template <typename T>
Array<T>::~Array(){
	delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& inst) {
	_n = inst._n;
	_array = new T [inst._n];
	for (unsigned int i = 0; i < inst._n; i++)
		_array[i] = inst._array[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= (int)_n)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= (int)_n)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
int Array<T>::size() const {
	return _n;
}