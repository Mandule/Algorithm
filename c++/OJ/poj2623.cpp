#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=252525;
long long num[maxn];
int n;
double median;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
        sort(num+1,num+n+1);
        if(n%2==0)
        {
            num[n/2]+=num[n/2+1];
            median=num[n/2]*1.0/2;
        }
        else
	        median=num[(n+1)/2];
        printf("%.1lf\n",median);
    }
    return 0;
}
