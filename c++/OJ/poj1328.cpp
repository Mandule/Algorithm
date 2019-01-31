#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct state {
	double start;
	double end;
	bool operator <(const state &other)const {
		return end < other.end;
	}
} s[1001];
int d;

void calculate(int x, int y, int i) {
	double	val;
	val = sqrt(double(d * d - y * y));
	s[i].start = x - val;
	s[i].end = x + val;
}


int main() {
	int n;
	int number = 1;
	while (scanf("%d%d", &n, &d) != EOF) {
		if (n == 0 && d == 0) break;
		int x, y;
		bool can = true;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			if (abs(y) > d) can = false;
			calculate(x, y, i);
		}
		if (!can) {
			cout << "Case " << number++ << ": " << -1 << endl;
			continue;
		}
		sort(s, s + n);
		int ans = 1;
		double tmp = s[0].end;
		for (int i = 1; i < n; i++) {
			if (s[i].start > tmp) {
				ans++;
				tmp = s[i].end;
			}
		}
		cout << "Case " << number++ << ": " << ans << endl;
	}
	return 0;
}
