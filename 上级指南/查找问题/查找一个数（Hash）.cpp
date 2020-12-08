#include <stdio.h>
int n;
int num[200];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<200;i++){
			num[i]=-1;
		}
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			num[x]=i;
		}
		scanf("%d",&x);
		printf("%d",num[x]);
	}
	return 0;
}
