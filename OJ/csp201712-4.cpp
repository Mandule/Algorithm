#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

struct edge{
	int type;	//存储道路类型
	int next;
	int cost;
};

vector<edge> E[501];
int mark[501];
int dis[501];
int typ[501];	//存储当前结点是由小路到达还是由大路到达，mark=1 时有效。

int dp[501][501];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	while(cin>>n>>m){
		memset(dp,-1,sizeof(dp));
		bool hasSmall = false;
		for(int i=1;i<=n;i++){	//初始化
			E[i].clear();
			mark[i] = 0;
			dis[i] = -1;
			typ[i] = 0;
		}
		for(int i=0;i<m;i++){		//读入道路信息
			int t,a,b,c;
			cin>>t>>a>>b>>c;
			if(t == 0){			//大道
				edge tmp;
				tmp.next = b;
				tmp.cost = c;
				tmp.type = 0;
				E[a].push_back(tmp);
				tmp.next = a;
				E[b].push_back(tmp);	
			}
			else{		//小道
				hasSmall = true;
				dp[a][b] = c;
				dp[b][a] = c;
			}
		}
		if(hasSmall){
			for(int k=1;k<=n;k++){		//求出只有小道的情况下每个路口最短路径
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dp[i][k] == -1 || dp[k][j] == -1) continue;
						if(dp[i][j] == -1 || dp[i][k] + dp[k][j] < dp[i][j]){
							dp[i][j] = dp[i][k]+dp[k][j];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){	//将小道转换为大道
				edge tmp;
				for(int j=1;j<=n;j++){
					if(i!=j && dp[i][j] != -1){
						tmp.next = j;
						tmp.type = 1;
						tmp.cost = dp[i][j]*dp[i][j];
						E[i].push_back(tmp);
					}
				}
			}
		}
		mark[1] = 1;
		dis[1] = 0;
		typ[1] = 0;
		int newp = 1;
		for(int k=1;k<n;k++){	//每次选出一个dis最小的结点，一共要选n-1次
			for(int i=0;i<E[newp].size();i++){	//跟新newp相邻节点的距离值
				int next = E[newp][i].next;
				int cost = E[newp][i].cost;
				int type = E[newp][i].type;
				if(mark[next] == 1) continue;
				if(typ[newp] == 1 && type == 1) continue;
				if(dis[next] == -1 || dis[next] > dis[newp]+cost){
					dis[next] = dis[newp] + cost;
					typ[next] = type;
				}
			}
			//取当前dis最小的结点加入已经访问的集合中
			int min_dis = INT_MAX;
			for(int i=1;i<=n;i++){
				if(mark[i] == 1 || dis[i] == -1) continue;
				if( min_dis > dis[i] ){
					min_dis = dis[i];
					newp = i;
				}
			}
			mark[newp] = 1;
		}
		cout<<dis[n]<<endl;
	}
}