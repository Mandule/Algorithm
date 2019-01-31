#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n,k;
int dp[2000][1000];
int w[2000];


int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++)
			cin>>w[i];
		sort(w+1,w+1+n);
		for(int i=1;i<=n;i++) dp[i][0] = 0;
		for(int i=1;i<=k;i++){
			for(int j=i*2;j<=n;j++){
				int tmp = pow(w[j]-w[j-1],2);
				if(j==i*2) dp[j][i] = dp[j-2][i-1]+tmp;
				else{
					dp[j][i] = min(dp[j-1][i],dp[j-2][i-1]+tmp);
				}
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
} 
