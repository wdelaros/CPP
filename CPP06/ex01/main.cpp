#include <cstdint>
#include <iostream>

struct Data {
	char c;
	int i;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	{
		Data *data = new Data;

		data->c = 'E';
		data->i = 69;
		uintptr_t no = serialize(data);
		Data *ptr = deserialize(no);
		std::cout << ptr->c << std::endl;
		std::cout << ptr->i << std::endl;
		delete data;
	}
	{
		Data data;

		std::cout << &data << std::endl;
		deserialize(serialize(&data));
		std::cout << &data << std::endl;
	}
	return 0;
}