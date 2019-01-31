
#include<stdio.h>
int a[15];
int main ()
{
	int s,d;
	while (scanf("%d%d",&s,&d)==2)
	{
		int sum=0;
		int i,j;
		for(i=5;i>=0;i--)       //一定要写成i>=0   若写成i>0可能出现一种情况i=1的时候sum>0 然后由于i>0退出了  sum仍然>0 
		{                      //写成i>=0 则上面那种情况变成i=1时sum>0,i=0时sum<0 break 
			sum=i*s-(5-i)*d;
			if(sum<0)break;
		}
		for(j=0;j<i;j++)
			a[j]=s;
		for(j=i;j<5;j++)
			a[j]=-d;
		for(i=5;i<12;i++)
		{
			a[i]=a[i-5];
			sum+=a[i];
		}
		if(sum>0)
		printf("%d\n",sum);
		else printf("Deficit\n");
	}
	return 0;
}
