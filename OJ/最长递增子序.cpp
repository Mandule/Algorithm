#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int dp[30];
int num[30];
int k;

int main(){
	while(scanf("%d",&k)!=EOF){
		for(int i=1;i<=k;i++)
			cin>>num[i];
		for(int i=1;i<=k;i++){
			dp[i] = 1;
			for(int j=1;j<i;j++){
				if(num[i] > num[j])
					dp[i] = max(dp[j]+1,dp[i]);
			}
			cout<<dp[i]<<endl;
		}
		int ans=1;
		for(int i=1;i<=k;i++)
			ans = max(ans,dp[i]);
		cout<<ans<<endl;
	}
	return 0;
}
