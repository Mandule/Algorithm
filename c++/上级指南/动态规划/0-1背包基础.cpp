#include <cstdio>
#include <iostream> 
#include <climits>
#include <cmath>
using namespace std;

int dp[101][1001];
int t[101];
int m[101];

int main(){
	int T,M;
	while(scanf("%d%d",&T,&M)!=EOF){
		for(int i=1;i<=M;i++)
			cin>>t[i]>>m[i];
		for(int j=1;j<=T;j++)
			dp[0][j]=0;			//状态存在，但值为0 
		for(int i=1;i<=M;i++){
			for(int j=T;j>=t[i];j--)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-t[i]]+m[i]);
			for(int j=0;j<t[i];j++)
				dp[i][j] = dp[i-1][j];
		}
		
//		空间复杂度优化 
//		for(int j=1;j<=T;j++)
//			dp[j]=0;		 
//		for(int i=1;i<=M;i++){
//			for(int j=T;j>=t[i];j--){
//				dp[j] = max(dp[j],dp[j-t[i]]+m[i]);
//			}
//		}
		
		cout<<dp[M][T]<<endl;
	}
	return 0;
}


