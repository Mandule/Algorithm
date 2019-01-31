#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n,k;
int weight[2001];
int dp[1001][2001];

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			cin>>weight[i];
		}
		sort(weight+1,weight+1+n);
		for(int j=1;j<=n;j++){
			dp[0][j]=0;
		}
		for(int i=1;i<=k;i++){
			for(int j=2*i;j<=n;j++){
				int tmp = dp[i][j-2]+(weight[j]-weight[j-1])*(weight[j]-weight[j-1]);
				if(j==2*i)
					dp[i][j] = tmp;
				else
					dp[i][j] = min(tmp,dp[i][j-1]);
			}
		}
		cout<<dp[k][n]<<endl;
	}
	return 0;
} 
