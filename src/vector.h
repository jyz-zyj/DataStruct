#pragma once
#include"default.h"
template<typename T> class Vector {
private:
	T* _elem;
	Rank _size;
	Rank _capacity;
public:
	Vector() {
		_elem = new T[default_size];
		_size = 0;
		_capacity = default_size;
	}
	Vector(const Vector<T>& other_vector) {
		_size = other_vector._size;
		_capacity = other_vector._capacity;
		_elem = new T[_capacity];
		for (Rank i = 0; i < _size; i++) {
			_elem[i] = other_vector._elem[i];
		}
	}
<<<<<<< HEAD
	Vector(Rank n, Rank m,T const& e) {
		_size = n;
		_capacity = m;
		_elem = new T[_capacity];
		for (Rank i = 0; i < _size; i++) {
			_elem[i] = e;
		}
	}
=======
>>>>>>> 3b515b7883902ee1cb3c9181070018c1541cc028
	void copyform(T* const A, Rank lo, Rank hi) {
		_size = hi - lo;
		_elem = new T[_capacity = _size];
		for (Rank i = 0; i < _size; i++) {
			_elem[i] = A[lo];
			lo++;
		}
	}
	~Vector() {
		delete[] _elem;
	}
	int size() {
		return _size;
	}
	void expand() {
		if (_size < _capacity)
			return;
		T* old_elem = _elem;
		_elem = new T[_capacity <<= 1];
		for (Rank i = 0; i < _size; i++) {
			_elem[i] = old_elem[i];
		}
		delete[] old_elem;
	}
	T insert(T const& e) {
		expand();
		_elem[_size] = e;
		_size++;
		return e;
	}
<<<<<<< HEAD
	T remove(Rank i) {
		T back = _elem[i];
		for (i; i < _size - 1; i++) {
			_elem[i] = _elem[i + 1];
		}
		_size--;
		return back;
=======
	T remove() {
		_size--;
		T result = _elem[_size];
		return	result ;
>>>>>>> 3b515b7883902ee1cb3c9181070018c1541cc028
	}
	T& operator[](Rank r) {
		if (r < 0 || r >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _elem[r];
	}
	Vector& operator=(const Vector<T>& other_vector) {
		if (this != &other_vector) {
			delete[] _elem;
			_size = other_vector._size;
			_capacity = other_vector._capacity;
			_elem = new T[_capacity];
			for (Rank i = 0; i < _size; i++) {
				_elem[i] = other_vector._elem[i];
			}
		}
		return *this;
	}
	Rank find(T const e) {
		for (Rank i = 0; i < _size; i++)
			if (_elem[i] == e)
				return i;
		return -1;
	}
	Rank search(T const e) {
		Rank lo = 0, hi = _size;
		while (lo < hi) {
			Rank mi = lo + (hi - lo) / 2;
			if (e < _elem[mi])
				hi = mi;
			else
				lo = mi + 1;
		}
		return lo - 1;
	}
	void print() {
		std::cout << "[ ";
		for (int i = 0; i < _size; i++) {
			std::cout << _elem[i] << " ";
		}
		std::cout << "]" << std::endl;
	}
};