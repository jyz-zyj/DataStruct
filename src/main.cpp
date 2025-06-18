#include"vector.h"
int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Vector<int> v;
	v.copyform(a, 0, 10);
	v.remove(0);
	v.print();
	return 0;
}