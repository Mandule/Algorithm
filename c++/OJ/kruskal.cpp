#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100
using namespace std;

struct Edge {
	int v1;
	int v2;
	int cost;
	bool operator < (const Edge& other)const {
		return cost < other.cost;
	}
} edge[5000];


int Node[N];

void init() {
	for (int i = 0; i < N; i++)
		Node[i] = -1;
}

int findRoot(int i) {
	if (Node[i] == -1) return i;
	int root = findRoot(Node[i]);
	Node[i] = root;
	return root;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		init();
		int size = n * (n - 1) / 2;
		int ans = 0;
		for (int i = 0; i < size; i++)
			cin >> edge[i].v1 >> edge[i].v2 >> edge[i].cost;
		sort(edge, edge + size);
		for (int i = 0; i < size; i++) {
			int v1 = edge[i].v1;
			int v2 = edge[i].v2;
			int cost = edge[i].cost;
			int a = findRoot(v1);
			int b = findRoot(v2);
			if (a != b) {
				Node[b] = a;
				ans += cost;
			}
		}
		cout << ans << endl;
	}

	return 0;
}




