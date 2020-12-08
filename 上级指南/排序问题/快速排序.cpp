#include <stdio.h>
#include <algorithm>
using namespace std;
//快速排序时间复杂度O（nlog2n）
//1<=n<=10000
//不能用冒泡排序，复杂度已经超出百万级别 
int main(){
	int n;
	int buf[10000];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n);		//快速排序重载形式 
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
} 
