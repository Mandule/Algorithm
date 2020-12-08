#include <cstdio>
#include <iostream>
#define MAX_N 1000000

using namespace std;

bool isPrime[MAX_N + 1];

void initPrime() {
	for (int i = 0; i < MAX_N; i++)
		isPrime[i] = 1;
	for (int i = 2; i * i < MAX_N; i++) {
		if (isPrime[i])
			for (int j = i * i; j <= MAX_N; j += i)
				isPrime[j] = 0;
	}
}

int main() {
	int n;
	
	initPrime();
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int i;
		for (i = 3; i <= n / 2; i += 2)
			if (isPrime[i] && isPrime[n - i]) break;
		cout << n << " = " << i << " + " << n - i << endl;
	}

	return 0;
}
