#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int Node[1000];

void init(){
	for(int i=0;i<1000;i++)
		Node[i] = -1;
}

int findRoot(int i){
	if(Node[i]==-1) return i;
	int root = findRoot(Node[i]);
	Node[i] = root;
	return root;
}


int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		init();
		int a,b;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			a = findRoot(a);
			b = findRoot(b);
			if(a!=b) Node[b] = a;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(Node[i]==-1) ans++; 
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
