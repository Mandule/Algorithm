#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;

int village[101];
struct edge{
	int a,b;
	int weight;
	bool operator < (const edge& other) const{
		return weight < other.weight;
	}
}edge[5000];

void init(){
	for(int i=0;i<101;i++){
		village[i]=-1;
	}
}

int getRoot(int x){
	if(village[x]==-1)	return x;
	int root = getRoot(village[x]);
	village[x] = root;
	return root;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int nEdge = n*(n-1)/2;
		init(); 
		for(int i=0;i<nEdge;i++){
			cin>>edge[i].a>>edge[i].b>>edge[i].weight;
		}
		sort(edge,edge+nEdge);
		int ans = 0;
		for(int i=0;i<nEdge;i++){
			int a=edge[i].a;
			int b=edge[i].b;
			int w=edge[i].weight;
			a = getRoot(a);
			b = getRoot(b);
			if( a != b ){
				village[b] = a;
				ans += w;
			}
		}
		cout<<ans<<endl;
	}
}









