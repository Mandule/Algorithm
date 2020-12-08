#include <cstdio>
#include <iostream>
#define OFF 500000

int hash[1000001];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			hash[tmp + OFF] = 1;
		}
		for (int i = 500000 + OFF; i >= -500000 + OFF; i--) {
			if (hash[i] == 1) {
				printf("%d ", i - OFF);
				m--;
				if (m == 0) break;
			}
		}
		printf("\n");
	}
	return 0;
}
