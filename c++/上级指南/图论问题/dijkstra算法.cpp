#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct E{
	int next;
	int cost;
};
vector<E> edge[101];
bool mark[101];
int dis[101];
int pre[101];

void init(){
	for(int i=0;i<101;i++){
		mark[i] = false;
		dis[i] = -1;
		edge[i].clear();
		pre[i]=-1;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		init();
		for(int i=0;i<m;i++){
			int a,b;
			E tmp;
			cin>>a>>b>>tmp.cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		mark[1] = true;
		dis[1] = 0;
		int newp = 1;
		int k=n-1;
		while(k--){
			for(int i=0;i<edge[newp].size();i++){
				int next = edge[newp][i].next;
				int c = edge[newp][i].cost;
				if(mark[next]) continue;
				if(dis[next] == -1 || dis[next] > dis[newp]+c){
					dis[next] = dis[newp]+c;
					pre[next] = newp;
				}
			}
			
			int min = INT_MAX;
			for(int i=1;i<=n;i++){
				if(mark[i] || dis[i] == -1) continue;
				if(dis[i]<min){
					min = dis[i];
					newp = i;
				}
			}
			mark[newp]= true;
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}


















