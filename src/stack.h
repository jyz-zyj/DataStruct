#pragma once
#include"default.h"
template<typename T> class Stack {
private:
	T* _elem;
	Rank _size;
	Rank _capacity;
public:
	Stack() {
		_elem = new T[default_size];
		_size = 0;
		_capacity = default_size;
	}
	~Stack() {
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
	T push(T const e) {
		expand();
		_elem[_size] = e;
		_size++;
		return e;
	}
	T pop() {
		_size--;
		return _elem[_size];
	}
	T top() {
		return _elem[_size - 1];
	}
};
