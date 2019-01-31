#define LOCAL
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

struct E{
	int next;
	int d;
	int p;
};
int n,m;
int s,t;
vector<E> edge[1005];
int vis[1005];
int dis[1005];
int cost[1005];

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while(cin>>n>>m && (n+m)){
		memset(vis,-1,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		for(int i=0;i<m;i++){
			int a,b,d,p;
			cin>>a>>b>>d>>p;
			E tmp;
			tmp.next = b;
			tmp.d = d;
			tmp.p = p;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		cin>>s>>t;
		vis[s] = 1;
		dis[s] = 0;
		cost[s] = 0;
		int newp = s;
		while(vis[t] == -1){
			for(int i=0;i<edge[newp].size();i++){
				int next = edge[newp][i].next;
				int d = edge[newp][i].d;
				int p = edge[newp][i].p;
				if(vis[next] == 1) continue;
				if(dis[next] == -1 || dis[newp]+d < dis[next] ){
					dis[next] = dis[newp]+d;
					cost[next] = cost[newp]+p;
				}else if(dis[newp]+d == dis[next] && cost[newp]+p < cost[next])
					cost[next] = cost[newp]+p;
			}
			int min_d = INT_MAX;
			int min_c = INT_MAX;
			for(int i=1;i<=n;i++){
				if(vis[i]==1 || dis[i]==-1) continue;
				if(dis[i] < min_d){
					min_d = dis[i];
					min_c = cost[i];
 					newp = i; 
				}
				else if(dis[i] == min_d && cost[i] < min_c){
					min_c = cost[i];
					newp = i;
				}
			}
			vis[newp] = 1;
		}
		cout<<dis[t]<<" "<<cost[t]<<endl;
	}
	return 0;
}