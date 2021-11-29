#include <cassert>
#include <cstring>
#include <iostream>

template<typename T> class Vec {
private:
	unsigned int m_Capacity = 4;
	unsigned int m_Size = 0;
	T *data;

	void _increaseCapacity() {
		m_Capacity *= 2;
		T *newArr = new T[m_Capacity];
		memcpy(newArr, data, sizeof(T) * m_Size);
		delete[] data;
		data = newArr;
	}

	void _shrinkCapacity() {
		T *newArr = new T[m_Capacity / 2];
		memcpy(newArr, data, sizeof(T) * m_Size);
		delete[] data;
		data = newArr;
	}

public:
	Vec<T>() : data(new T[m_Capacity]) { }

	Vec<T>(T *arr) {
		if (arr != nullptr) {
			int len = sizeof arr / sizeof(arr[0]) + 1;
			while (m_Capacity < len)
				m_Capacity *= 2;
			data = new T[m_Capacity];
			memcpy(data, arr, sizeof(T) * len);
			m_Size = len;
		}
	}

	void add(T value) {
		if (m_Size == m_Capacity) {
			_increaseCapacity();
		}
		data[m_Size++] = value;
	}

	unsigned int size() {
		return m_Size;
	}

	T get(unsigned int index) {
		assert(index < m_Size);
		return data[index];
	}

	T remove(unsigned int index) {
		assert(index < m_Size && index >= 0);

		T target = data[index];
		for (int i = 0; i < m_Size - 1; i++) {
			data[i] = data[i + 1];
		}
		--m_Size;

		if (m_Capacity <= m_Size)
			_shrinkCapacity();
		return target;
	}

	void print() {
		std::cout << "[";
		int i = 0;
		while (i < m_Size - 1)
			std::cout << data[i++] << ", ";
		std::cout << data[i] << "]" << std::endl;
	}
};

int main() {
	auto *vec = new Vec<int>();
	vec->add(5);
	vec->add(7);
	vec->add(9);
	vec->add(2);
	vec->add(24);
	assert(5 == vec->size());
	vec->print();

	vec->remove(2);
	vec->remove(1);
	vec->remove(0);
	assert(2 == vec->size());

	auto *arr = new float[3] {2.2, 1.0, 3.6};
	auto *v2 = new Vec<float>(arr);
	assert(3 == v2->size());
	v2->print();
	return 0;
}
