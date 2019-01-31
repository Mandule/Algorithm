#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int dp[101][101];
char str1[101];
char str2[101];


int main(){
	while(scanf("%s%s",str1,str2)!=EOF){
		int len1,len2;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(int i=0;i<=len1;i++)
			dp[i][0] = 0;
		for(int i=0;i<=len2;i++)
			dp[0][i] = 0;
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(str1[i-1] == str2[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	
	return 0;
} 
