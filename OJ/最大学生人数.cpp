#include <cstdio>
#include <iostream>
#include <cmath> 
#define N 1001
using namespace std;


int Node[N];
int Sum[N];

void init(){
	for(int i=0;i<N;i++){
		Node[i]=-1;
		Sum[i]=1;
	}
}


int findRoot(int i){
	if(Node[i]==-1) return i;
	int root = findRoot(Node[i]);
	Node[i] = root;
	return root; 
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,b;
		init();
		for(int i=0;i<n;i++){
			cin>>a>>b;
			a = findRoot(a);
			b = findRoot(b);
			if(a!=b){
				Node[b] = a;
				Sum[a] += Sum[b];
			}
		}
		int ans = 1;
		for(int i=1;i<N;i++){
			if(Node[i] == -1 && Sum[i]>ans)
				ans = Sum[i];
		}
		cout<<ans<<endl;
	}	
	return 0;
}
