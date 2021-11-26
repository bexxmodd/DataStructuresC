#include <cassert>
#include <cstring>
#include <iostream>

template<typename T> class Vec {
private:
	unsigned size = 0;
	T *data;

	void _increase_capacity() {
		T *new_arr = new T[2 * size];
		memcpy(data, new_arr, size);
		data = new_arr;
		delete[] data;
	}

	int _size() {
		return sizeof data / sizeof(data[0]);
	}

public:
	static const unsigned int INITIAL_CAPACITY = 4;

	Vec<T>() : data(new T[INITIAL_CAPACITY]) { }

	explicit Vec<T>(T *arr) {
		if (arr != nullptr) {
			int len = sizeof arr / sizeof(arr[0]);
			data = new T[len];
			memcpy(data, arr, len);
			size = len;
		}
	}

	void add(T value) {
		if (size == _size()) {
			_increase_capacity();
		}
		data[size++] = value;
	}

	int length() {
		return size;
	}
};

int main() {
	auto *vec = new Vec<int>();
	vec->add(5);
	vec->add(7);
	vec->add(9);
	vec->add(2);
	vec->add(24);
	assert(5 == vec->length());
	return 0;
}
