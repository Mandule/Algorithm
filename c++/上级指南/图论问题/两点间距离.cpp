#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct E{
	int next;
	int dis;
	int cost;
};

vector<E> edge[1001];
int cos[1001];
int dis[1001];
bool mark[1001];

void init(int n){
	for(int i=1;i<=n;i++){
		edge[i].clear();
		dis[i]=-1;
		cos[i]= 0;
		mark[i] = false;
	}
}


int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n ==0 && m==0 ) break;
		init(n);
		int s,t,newp;
		for(int i=0;i<m;i++){
			int a,b;
			E tmp;
			cin>>a>>b>>tmp.dis>>tmp.cost;
			tmp.next = a;
			edge[b].push_back(tmp);
			tmp.next = b;
			edge[a].push_back(tmp);
		}
		cin>>s>>t;
		dis[s] = 0;
		cos[s] = 0;
		mark[s] = true;
		newp = s;
		for(int k=0;k<n-1;k++){
			for(int j=0;j<edge[newp].size();j++){
				int t = edge[newp][j].next;
				int d = edge[newp][j].dis;
				int c = edge[newp][j].cost;
				if(mark[t]) continue;
				if(dis[t] == -1 || dis[newp]+d < dis[t] || dis[t] == dis[newp]+d && cos[t]>cos[newp]+c ){
					dis[t] = dis[newp]+d;
					cos[t] = cos[newp]+c;
				}
			}
			int min = INT_MAX;
			for(int i=1;i<=n;i++){
				if(mark[i]) continue;
				if(dis[i] == -1) continue;
				if(dis[i] < min){
					min = dis[i];
					newp = i;
				}
			}
			mark[newp] = true;
		}
		cout<<dis[t]<<" "<<cos[t]<<endl;
	}
	return 0;
}






