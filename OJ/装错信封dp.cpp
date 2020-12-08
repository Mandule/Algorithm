#include <cstdio>
#include <iostream>
using namespace std;

long long dp[21];

int main(){
	int n;
	dp[1] = 0;
	dp[2] = 1;
	for(int i=3;i<=20;i++)
		dp[i] = (i-1)*dp[i-1] + (i-1)*dp[i-2];
	while(scanf("%d",&n)!=EOF){
		cout<<dp[n]<<endl;
	}
}
