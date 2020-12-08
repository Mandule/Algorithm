#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int num[n];
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<m;i++){
			make_heap(num+i,num+n);
			printf("%d ",num[i]);
		}
		printf("\n"); 
	} 
} 
