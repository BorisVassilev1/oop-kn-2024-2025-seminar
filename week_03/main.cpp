#include <iostream>

template <class T>
class Array {
	std::size_t size;
	T		   *ptr;

	void free() { delete[] ptr; }

   public:
	explicit Array(std::size_t size) : size(size), ptr(new T[size]) {}
	Array(const Array &other) : size(other.size), ptr(new T[size]) {
		for (std::size_t i = 0; i < size; ++i)
			ptr[i] = other.ptr[i];
	}
	~Array() { free(); }

	Array &operator=(const Array &other) {
		free();
		ptr = new int[other.size];
		for (std::size_t i = 0; i < size; ++i)
			ptr[i] = other.ptr[i];
		return *this;
	}

	T &get(std::size_t i) { return ptr[i]; }
	const T &get(std::size_t i) const { return ptr[i]; }

};

int main() {
	Array<int> arr = Array<int>(5);
	// Array<int> arr = 5;

	const Array<int> arr2 = Array<int>(10);

	arr = arr2;

	arr.get(0) = 10;
	std::cout << arr.get(0) << std::endl;

	//arr2.get(0) = 10;
	std::cout << arr2.get(0) << std::endl;
}
