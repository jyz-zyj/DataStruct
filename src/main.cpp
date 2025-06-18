#include"vector.h"
int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Vector<Vector<int>> v;
	for (int i = 1; i < 5; i++) {
		Vector<int> temp;
		temp.copyform(a, 0, 10);
		v.insert(temp);
	}
	for (int i = 0; i < v.size(); i++) {
		v[i].print();
	}
	return 0;
}