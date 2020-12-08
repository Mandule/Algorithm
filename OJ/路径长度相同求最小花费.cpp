#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define N 101
using namespace std;

struct Edge{
	int next;
	int cost;	
	int spend;
}; 

vector<Edge> edge[N];
int mark[N];
int cost[N];
int spend[N];

void init(){
	for(int i=0;i<N;i++){
		edge[i].clear();
		mark[i] = 0;
		cost[i] = -1;
		spend[i] = -1; 
	}
}

int main(){
	int n,m;
	int s,t; 
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		if(n==0 && m==0) break;
		for(int i=0;i<m;i++){
			int a,b,c,d;
			Edge tmp;
			cin>>a>>b>>c>>d;
			tmp.next = b;
			tmp.cost = c;
			tmp.spend = d;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp); 
		}
		cin>>s>>t;
		//算法 
		mark[s] = 1;
		cost[s] = 0;
		spend[s] = 0;
		int newP = s;
		for(int i=1;i<n;i++){
			//更新
			for(int j=0;j<edge[newP].size();j++){ 
				int next = edge[newP][j].next;
				int c = edge[newP][j].cost;
				int s = edge[newP][j].spend;
				if(mark[next]==1) continue;
				if(cost[next]==-1 || cost[next]>cost[newP]+c){
					cost[next] = cost[newP]+c;
					spend[next] = spend[newP]+s;
				}else
				if(cost[next] == cost[newP]+c && spend[next] >spend[newP]+s)
					spend[next] = spend[newP]+s;
			}			
			//取当前最短 
			int min = INT_MAX;
			for(int j=0;j<n;j++){
				if(mark[j]==1 || cost[j]==-1) continue;
				if(cost[j]<min){
					min = cost[j];
					newP = j;
				}else
				if(cost[j]==min && spend[j]<spend[newP])
					newP = j;
			}
			//加入集合 
			mark[newP] = 1;
		}
		cout<<cost[t]<<" "<<spend[t]<<endl;
	}
	
}
