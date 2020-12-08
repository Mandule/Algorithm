#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 125;

int dp[MAX_N][MAX_N];


void init(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=120;i++){
		dp[i][1] = dp[1][i] = 1;
	}
	for(int i=2;i<=120;i++){
		for(int j=2;j<=120;j++){
			if(j==i) dp[i][j] = dp[i][j-1] + 1;
			else if(j>i) dp[i][j] = dp[i][i];
			else dp[i][j] = dp[i][j-1] + dp[i-j][j];
		}
	}
}

int main(){
    int n;
    init();
    while(cin>>n){
    	cout<<dp[n][n]<<endl;;
    }
    return 0;
}



#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n;
int dp[125];//dp[i]表示凑成i的方案数
 
int main() {
    while(1==scanf("%d",&n)) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;++i) {
            for(int j=i;j<=n;++j) {//从前往后是完全背包，从后往前是01背包
                dp[j]+=dp[j-i];
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}