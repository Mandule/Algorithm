#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char str1[100];
char str2[100];
int dp[100][100];

int main()
{
	while(scanf("%s%s",&str1,&str2)!=EOF)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		for(int i=0;i<len1;i++)
			dp[i][0]=0;
		for(int j=0;j<len2;j++)
			dp[0][j]=0;
		for(int i=1;i<len1;i++)
		{
			for(int j=1;j<len2;j++)
			{
				if(str1[i]==str2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}		
		cout<<dp[len1-1][len2-1]<<endl;
	}
	return 0;
}
