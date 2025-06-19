#pragma once
#include "graph.h"
#include "vector.h"
#include "queue.h"
template<typename Tv> class Vertex {
public:
	Tv data;
	int inDegree;
	int outDegree;
	int dTime;
	int fTime;
	VStatus status;
	int parent;
	int priority;
	Vertex(Tv const& d = Tv(), int in = 0, int out = 0, VStatus s = Undiscovered, int p = -1, int prio = 0)
		: data(d), inDegree(in), outDegree(out), status(s), parent(p), priority(prio) {
	}
};
template<typename Te> class Edge {
public:
	Te data;
	int weight;
	EType type;
	Edge(Te const& d = Te(), int w = 0, EType t = Undetermined) : data(d), weight(w), type(t) {}
};

template<typename Tv, typename Te> class GraphMatrix : public Graph<Tv, Te> {
private:
	Vector<Vertex<Tv>> V;
	Vector<Vector<Edge<Te>*>> E;
public:
	GraphMatrix() {
		n = 0, e = 0;
	}
	~GraphMatrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				delete E[i][j];
			}
		}
	}
	bool exists(int i, int j) {
		if (i >= 0 && i < n && j >= 0 && j < n && E[i][j] != nullptr)
			return true;
		return false;
	}
	EType& type(int i, int j) {
		return E[i][j]->type;
	}
	Te& edge(int i, int j) {
		return E[i][j]->data;
	}
	int& weight(int i, int j) {
		return E[i][j]->weight;
	}
	void insertEdge(Te const& edge, int weight, int i, int j) {
		if (exists(i, j))
			return;
		E[i][j] = new Edge<Te>(edge, weight, Undetermined);
		e++;
		V[i].outDegree++;
		V[j].inDegree++;
	}
	Te deleteEdge(int i, int j) {
		if (!exists(i, j))
			return;
		Te back = E[i][j]->data;
		delete E[i][j];
		E[i][j] = nullptr;
		e--;
		V[i].outDegree--;
		V[j].inDegree--;
		return back;
	}

	int insertVertex(Tv const& vertex) {
		for (int i = 0; i < n; i++) {
			e[i].insert(nullptr);
		}
		n++;
		E.insert(Vector<Edge<Te>*>(n, n, nullptr));
		return V.insert(Vertex<Tv>(vertex));
	}
	int deleteVertex(int i) {
		for (int j = 0; j < n; j++) {
			if (exists(i, j)) {
				delete E[i][j];
				V[j].inDegree--;
				e--;
			}
		}
		E.remove(i);
		n--;
		Tv back = V[i].data;
		V.remove(i);
		for (int j = 0; j < n; j++) {
			if (Edge<Te> e = E[j].remove(i)) {
				delete e;
				V[j].outDegree--;
				e--;
			}
		}
		return back;
	}
	VStatus& status(Rank i) {
		return V[i].status;
	}
	void bfs(Rank s) {
		reset();
		int clock = 0;
		Rank v = s;
		do
		{
			if (status(v) == Undiscovered)
				BFS(v, clock);
		} while (s!= ( v = ( ++v % n)));
	}
	void BFS(Rank v, int& clock) {
		Queue<int> q;
		status(v) = Discovered;
		q.enqueue(v);
		while (!q.empty()) {
			int v = q.dequeue();
			dTime(v) = ++clock;
			for (u = firstNbr(v); u > -1; u = nextNbr(v, u)) {
				if (status(u) == Undiscovered) {
					status(u) = Discovered;
					q.enqueue(u);
					type(v, u) = Tree;
					parent(u) = v;
				}
				else {
					type(v, u) = Cross;
				}
			}
			status(v) = Visited;
		}
	}
	Rank nextNbr(Rank v, Rank u) {
		while (-1 != --u && !exists(v, u));
		return u;
	}
	Rank firstNbr(Rank v) {
		return nextNbr(v, n);
	}
	int& dTime(int v) {
		return V[v].dTime;
	}
	int& fTime(int v) {
		return V[v].fTime;
	}
	EType& type(Rank v, Rank u) {
		return E[v][u]->type;
	}
	int& parent(Rank v) {
		return V[v].parent;
	}
};
