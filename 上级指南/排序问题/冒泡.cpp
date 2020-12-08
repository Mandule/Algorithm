#include <stdio.h>
//冒泡排序复杂度 O（N的平方）
//1<=n<=100,万级别，并未超过百万级别复杂度。 

int main(){								
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		for(int i=n-1;i>0;i--){			//每次冒泡，选择出最大的数。 
			for(int j=0;j<i;j++){
				if(buf[j]>buf[j+1]){
					int tmp = buf[j];
					buf[j] = buf[j+1];
					buf[j+1] = tmp;
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}
