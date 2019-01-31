#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

int map[4][4];
int ans = INT_MAX;

int go[][2] = {
	0, 1,
	0, -1,
	-1, 0,
	1, 0,
	0, 0
};

void initMap() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'w') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
}

bool isOK() {
	int ans = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ans += map[i][j];
	if (ans % 16 == 0) return true;
	else return false;
}


void turn(int x, int y) {
	if (x >= 0 && x < 4 && y >= 0 && y < 4)
		map[x][y] = !map[x][y];
}

void flip(int s) {
	int x = s / 4;
	int y = s % 4;
	for (int i = 0; i < 5; i++)
		turn(x + go[i][0], y + go[i][1]);
}

void DFS(int s, int n) {
	if (isOK()) {
		if (n < ans) ans = n;
		return;
	}
	if (s >= 16) return;
	DFS(s + 1, n);
	flip(s);
	DFS(s + 1, n + 1);
	flip(s);
}



int main() {
	initMap();
	DFS(0, 0);
	if (ans == INT_MAX) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}
