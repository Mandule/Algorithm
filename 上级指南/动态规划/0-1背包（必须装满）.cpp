#include <cstdio>
#include <iostream> 
#include <climits>
#include <cmath>
using namespace std;

int dp[1001];
int t[101];
int m[101];

int main(){
	int T,M;
	while(scanf("%d%d",&T,&M)!=EOF){
		for(int i=1;i<=M;i++)
			cin>>t[i]>>m[i];
		for(int j=1;j<=T;j++)
			dp[j]=INT_MIN;		//设置初始状态不存在，而不是为 0	 
		for(int i=1;i<=M;i++)
			for(int j=T;j>=t[i];j--)
				if(dp[j-t[i]]!=INT_MIN)			//如果前一个状态不存在 则不改变现有状态 
					dp[j] = max(dp[j],dp[j-t[i]]+m[i]);		
		cout<<dp[T]<<endl;
	}
	return 0;
}


