#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	while(b!=0){
		int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		int tmp = max(a, b);
		b = min(a, b);
		a = tmp;
		cout << gcd(a, b) << endl;
	}
	return 0;
}
