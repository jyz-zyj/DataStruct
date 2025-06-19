#include"vector.h"
#include"queue.h"
int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Vector<int> v;
	v.copyform(a, 0, 10);
	v.remove(0);
	v.print();
	Queue<int> T;
	for (int i = 0; i < 10; i++) {
		T.enqueue(i);
	}
	std::cout << "Queue elements: ";
	while (!T.empty()) {
		std::cout << T.dequeue() << " ";
	}
	return 0;
}