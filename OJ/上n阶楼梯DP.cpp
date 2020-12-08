#include <cstdio>
#include <iostream>
using namespace std;

long long dp[91];

int main(){
	int n;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=90;i++)
		dp[i] = dp[i-1]+dp[i-2];
	while(scanf("%d",&n)!=EOF){
		cout<<dp[n]<<endl;
	}
}
