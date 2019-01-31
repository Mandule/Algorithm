#include <cstdio>
#define OFFSET 500000
int Hash[1000001];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int num;
		for(int i=-500000;i<=500000;i++){
			Hash[i+OFFSET]=0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			Hash[num+OFFSET]=1;
		}
		for(int i=500000;i>=-500000;i--){
			if(Hash[i+OFFSET]==1){
				printf("%d ",i);
				m--;
				if(m==0){
					printf("\n");
					break;
				}
			}
		}
	} 
	return 0;
} 

a = 3;
d=23;