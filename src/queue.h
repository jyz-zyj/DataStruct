#pragma once
template<typename T>class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(T e) {
		data = e;
		next = nullptr;
		prev = nullptr;
	}
	Node() {
		next = nullptr;
		prev = nullptr;
	}
};		  
template<typename T>class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Queue() {
		head = new Node<T>();
		tail = new Node<T>();	
		head->next = tail;
		tail->prev = head;
	}
	~Queue() {
		clear();
		delete head;
		delete tail;
	}
	void clear() {
		while(!empty()) {
			dequeue(); // Dequeue until empty
		}
	}
	void enqueue(T e) {
		Node<T>* newNode = new Node<T>(e);
		newNode->prev = tail->prev;
		newNode->next = tail;
		tail->prev->next = newNode;
		tail->prev = newNode;
	}
	T dequeue() {
		Node<T>* toDelete = head->next;
		T data = toDelete->data; // Optional: store data if needed
		head->next = toDelete->next;
		toDelete->next->prev = head;
		delete toDelete;
		return data;
	}
	bool empty() {
		return head->next == tail;
	}
};
