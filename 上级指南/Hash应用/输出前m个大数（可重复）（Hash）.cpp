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
			Hash[num+OFFSET]++;
		}
		for(int i=500000;i>=-500000;i--){
			while(Hash[i+OFFSET]!=0){
				printf("%d ",i);
				m--;
				if(m==0){
					printf("\n");
					break;
				}
				Hash[i+OFFSET]--;
			}
			if(m==0){
				break;
			} 
		}
	} 
	return 0;
} 
