#pragma once
#include "default.h"

typedef enum {
	Undiscovered,
	Discovered,
	Visited
}VStatus;
typedef enum {
	Undetermined,
	Tree,
	Cross,
	Forward,
	Backward
}EType;
template<typename Tv, typename Te> class Graph {
private:
	void reset() {
		for (int i = 0; i < n; i++) {
			status[i] = Undiscovered;
			parent[i] = -1;
			priority[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			type[i] = Undetermined;
		}
	}
public:
	int n;
	int e;
};