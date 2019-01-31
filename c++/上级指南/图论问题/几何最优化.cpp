#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

struct point{
	float x,y;
	float operator - (const point &other) const{
		float ans;
		ans = pow(x-other.x,2)+pow(y-other.y,2);
		ans = sqrt(ans);
		return ans;
	}
}point[101];

struct edge{
	int a,b;
	float w;
	bool operator < (const edge &other) const{
		return w<other.w;
	}
}edge[5000];

int tree[100];

int getRoot(int x){
	if(tree[x]==-1) return x;
	int ans = getRoot(tree[x]);
	tree[x] = ans;
	return ans;
}
void init(){
	for(int i=0;i<100;i++){
		tree[i] = -1;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=0;i<n;i++){
			cin>>point[i].x>>point[i].y;
		}
		
		int nEdge = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edge[nEdge].a = i;
				edge[nEdge].b = j;
				edge[nEdge].w = point[i]-point[j];
				nEdge++;
			}
		}
		sort(edge,edge+nEdge);
		float ans=0;
		for(int i=0;i<nEdge;i++){
			int a = getRoot(edge[i].a);
			int b = getRoot(edge[i].b);
			if( a!= b){
				tree[b] = a;
				ans += edge[i].w;
			}
		}
		printf("%.2f\n",ans);
	}
}






