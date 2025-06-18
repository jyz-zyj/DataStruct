#include"vector.h"
int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
<<<<<<< HEAD
	Vector<int> v;
	v.copyform(a, 0, 10);
	v.remove(0);
	v.print();
=======
	Vector<Vector<int>> v;
	for (int i = 1; i < 5; i++) {
		Vector<int> temp;
		temp.copyform(a, 0, 10);
		v.insert(temp);
	}
	for (int i = 0; i < v.size(); i++) {
		v[i].print();
	}
>>>>>>> 3b515b7883902ee1cb3c9181070018c1541cc028
	return 0;
}