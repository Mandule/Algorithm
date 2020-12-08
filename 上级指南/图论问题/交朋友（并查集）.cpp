#include <cstdio>
#include <iostream>
#define MAX_BOY 1000001
using namespace std;

int node[MAX_BOY];
int num[MAX_BOY];
int n;

int findRoot(int x){
	if(node[x] == -1) return x;
	int tmp = findRoot(node[x]);
	node[x] = tmp;
	return tmp;
}

void init(){
	for(int i=0;i<MAX_BOY;i++){
		node[i]=-1;
		num[i]=1;
	}
}

int main (){
	while(scanf("%d",&n)!=EOF){
		int a,b;
		init();
		for(int i=0;i<n;i++){
			int b1,b2;
			cin>>b1>>b2;
			b1 = findRoot(b1);
			b2 = findRoot(b2);
			if(b1 != b2){
				node[b2] = b1;
				num[b1] += num[b2];
			}
		}
		int max=0;
		for(int i=1;i<MAX_BOY;i++){
			if(node[i]==-1 && num[i]>max) max = num[i];
		}
		cout<<max<<endl;
	}
	return 0;
} 
