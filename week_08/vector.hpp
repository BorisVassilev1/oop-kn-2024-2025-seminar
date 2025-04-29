#pragma once

#include <cassert>
#include <cstddef>
#include <functional>

template <class T>
class Vector {
	T*			arr;
	std::size_t capacity;
	std::size_t size;

   public:
	Vector();
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other);

	Vector(std::size_t size, const T& el);
	~Vector();

	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other);

	void	   Push(const T& x);
	Vector<T>& operator+=(const T& x) {
		Push(x);
		return *this;
	}
	void		Push(const T* src, std::size_t cnt);
	std::size_t Size() const;

	void clear();

	T&		 Get(int i);
	const T& Get(int i) const;

	T&		 operator[](int i) { return Get(i); }
	const T& operator[](int i) const { return Get(i); }

	Vector<T> Subvec(int i, int j) const;
	void	  Sort(std::function<bool(const T&, const T&)> f);

	Vector<T>& operator+=(const Vector<T>& other) { this->Push(other.arr, other.size); }
	Vector<T>  operator+(const Vector<T>& other) {
		 Vector<T> result = *this;
		 result += other;
		 return result;
	}

	using iterator = T*;
	iterator begin() { return arr; }
	iterator end() { return arr + size; }

	using const_iterator = const T*;
	const_iterator begin() const { return arr; }
	const_iterator end() const { return arr + size; }

	template <class T_ptr>
	class reverse_iterator_base {
		T_ptr p;
		reverse_iterator_base(T* p) : p(p) {}
		friend class Vector<T>;

	   public:
		reverse_iterator_base& operator++() {
			--p;
			return *this;
		}
		reverse_iterator_base operator++(int) {
			reverse_iterator_base it = *this;
			++*this;
			return it;
		}
		const T& operator*() const { return *p; }
		T&		 operator*() { return *p; }

		bool operator==(const reverse_iterator_base& other) const { return p == other.p; }
	};

	using reverse_iterator		 = reverse_iterator_base<T*>;
	using const_reverse_iterator = reverse_iterator_base<const T*>;

	reverse_iterator	   rbegin() { return arr + size - 1; }
	reverse_iterator	   rend() { return arr - 1; }
	const_reverse_iterator rbegin() const { return arr + size - 1; }
	const_reverse_iterator rend() const { return arr - 1; }

   private:
	void resize(std::size_t newSize);
};

template <class T>
Vector<T>::Vector() : arr(new T[1]), capacity(1), size(0) {}

template <class T>
Vector<T>::Vector(std::size_t size, const T& el) : arr(new T[size]), capacity(size), size(size) {
	for (std::size_t i = 0; i < size; ++i) {
		arr[i] = el;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) : arr(new T[other.Size()]), capacity(other.Size()), size(other.Size()) {
	for (std::size_t i = 0; i < size; ++i) {
		arr[i] = other.Get(i);
	}
}

template <class T>
Vector<T>::Vector(Vector<T>&& other) : arr(other.arr), capacity(other.capacity), size(other.size) {
	other.arr = nullptr;
}

template <class T>
Vector<T>::~Vector() {
	delete[] arr;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	clear();
	Push(other.arr, other.size);
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
	std::swap(arr, other.arr);
	std::swap(capacity, other.capacity);
	std::swap(size, other.size);
	return *this;
}

template <class T>
void Vector<T>::clear() {
	delete[] arr;
	arr		 = new T[1];
	size	 = 0;
	capacity = 1;
}

template <class T>
void Vector<T>::Push(const T& x) {
	if (size == capacity) resize(2 * capacity);
	arr[size++] = x;
}

template <class T>
void Vector<T>::Push(const T* src, std::size_t cnt) {
	if (size + cnt >= capacity + 1) {
		std::size_t newCapacity = capacity;
		while (size + cnt >= newCapacity + 1) {
			newCapacity *= 2;
		}
		resize(newCapacity);
	}
	for (std::size_t i = 0; i < cnt; ++i) {
		arr[Size() + i] = src[i];
	}
	size += cnt;
}

template <class T>
std::size_t Vector<T>::Size() const {
	return size;
}

template <class T>
T& Vector<T>::Get(int i) {
	return arr[i];
}

template <class T>
const T& Vector<T>::Get(int i) const {
	return arr[i];
}

template <class T>
Vector<T> Vector<T>::Subvec(int i, int j) const {
	Vector<T> res;
	assert(i <= j);
	res.Push(arr + i, j - i);
	return res;
}

template <class T>
void Vector<T>::Sort(std::function<bool(const T&, const T&)> f) {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size - 1 - i; ++j) {
			if (!f(arr[j], arr[j + 1])) { std::swap(arr[j], arr[j + 1]); }
		}
	}
}

template <class T>
void Vector<T>::resize(std::size_t newSize) {
	assert(newSize > size);
	T* new_arr = new T[newSize];
	for (size_t i = 0; i < size; ++i) {
		new_arr[i] = std::move(arr[i]);
	}
	capacity = newSize;
	delete[] arr;
	arr = new_arr;
}
