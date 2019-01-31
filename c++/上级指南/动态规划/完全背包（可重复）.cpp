#include <cstdio>
#include <iostream> 
#include <climits>
#include <cmath>
using namespace std;

int dp[1001];
int w[101];
int v[101];

int main(){
	int s,n;
	while(scanf("%d%d",&s,&n)!=EOF){
		for(int i=1;i<=n;i++)
			cin>>w[i]>>v[i];
		for(int j=1;j<=s;j++)
			dp[j]=0;			//dp[j] = INT_MIN 必须正好填满背包 
		for(int i=1;i<=n;i++){
			for(int j=w[i];j<=s;j++)
				if(dp[j-w[i]]!=INT_MIN)
					dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
		cout<<dp[s]<<endl;
	}
	return 0;
}

