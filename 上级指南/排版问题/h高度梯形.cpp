#include <cstdio>

int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		int n1 = (h-1)*2;
		int n2 = h;
		for(int i=0;i<h;i++){
			for(int j=0;j<n1;j++){
				printf(" ");
			}
			for(int j=0;j<n2;j++){
				printf("%c",'*');
			}
			printf("\n");
			n1 = n1-2;
			n2 = n2+2;
		}
	}
	return 0;
} 
