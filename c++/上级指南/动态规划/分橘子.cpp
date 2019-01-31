#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#define OFFSET 2000
using namespace std;

int dp[101][4001];
int w[101];

int main(){
	int k,n;
	cin>>k;
	while(k--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int j=-2000;j<=2000;j++)
		{
			dp[0][j+OFFSET] = INT_MIN;
		}
		dp[0][0+OFFSET]=0;
	
		for(int i=1;i<=n;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				int tmp1 = INT_MIN;
				int tmp2 = INT_MIN;
				if(j+w[i]<=2000  && dp[i-1][j+w[i]+OFFSET] != INT_MIN){
					tmp1 = dp[i-1][j+w[i]+OFFSET]+w[i];
				}
				if(j-w[i]>=-2000 && dp[i-1][j-w[i]+OFFSET] != INT_MIN){
					tmp2 = dp[i-1][j-w[i]+OFFSET]+w[i];
				}
				dp[i][j+OFFSET] = max(max(tmp1,tmp2),dp[i-1][j+OFFSET]);
			}
		}
		cout<<dp[n][0+OFFSET]/2<<endl;
	}	
	return 0;
} 
