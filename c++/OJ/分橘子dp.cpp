#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int OFF = 200;

int dp[101][401];
int w[101];
int n;

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			cin>>w[i];
		for(int i=-200;i<=200;i++)
			dp[0][i+OFF] = -1;
		dp[0][0+OFF] = 0;
		for(int i=1;i<=n;i++){
			for(int j=-200;j<=200;j++){
				dp[i][j+OFF] = -1;
				if(dp[i-1][j+OFF]!=-1)
					dp[i][j+OFF] = max(dp[i][j+OFF],dp[i-1][j+OFF]);					
				if(dp[i-1][j-w[i]+OFF]!=-1)
					dp[i][j+OFF] = max(dp[i][j+OFF],dp[i-1][j-w[i]+OFF]+w[i]);
				if(dp[i-1][j+w[i]+OFF]!=-1)
					dp[i][j+OFF] = max(dp[i][j+OFF],dp[i-1][j+w[i]+OFF]+w[i]);				
			}
		}
		cout<<dp[n][0+OFF]/2<<endl;
	}
	return 0;
}
