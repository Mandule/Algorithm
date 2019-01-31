#include <cstdio>
#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n && n) {
		int at = 0;
		int to;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> to;
			tmp = to - at;
			if (tmp > 0) ans += tmp * 6;
			else if (tmp < 0) ans -= tmp * 4;
			ans += 5;
			at = to;
		}
		cout << ans << endl;
	}
}
