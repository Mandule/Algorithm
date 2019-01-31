#include <cstdio>
#include <cmath>
#include <iostream>
#include <climits>
using namespace std;

int W, N;
int w[101];
int v[101];

int dp[1001];

int main() {
	while (scanf("%d%d", &W, &N) != EOF) {
		for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
		dp[0] = 0;
		for (int i = 1; i <= W; i++) 		//初始值不同，解决的问题也不同。
			dp[i] = INT_MIN;
		for (int i = 1; i <= N; i++) {
			for (int j = w[i]; j <= W; j++)	//遍历顺序不同，解决的问题也不同。
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
		cout << dp[W] << endl;
	}
	return 0;
}
