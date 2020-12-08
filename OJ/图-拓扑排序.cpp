#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m;

int edge[105][105];
int vis[105];
int topo[105];
int t;


bool dfs(int i){
	vis[i] = 0;
	for(int j=0;j<n;j++)if(edge[i][j]==1){
		if(vis[j] == 0) return false;
		else if(vis[j] == -1 &&  dfs(j)==false ) return false;
	}
	vis[i] = 1;
	topo[--t] = i;
	return true;
}


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while(cin>>n>>m && (n+m)){
		memset(edge,-1,sizeof(edge));
		memset(vis,-1,sizeof(vis));
		t=n;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			edge[a][b] = 1;
		}
		bool ans =true;
		for(int i=0;i<n;i++)if(vis[i] == -1){
			if(dfs(i) == false ) {
				cout<<"NO"<<endl;
				ans = false;
			}
		}

		if(ans)for(int i=0;i<n;i++)
			cout<<topo[i]<<" ";
		cout<<endl;
	}
	return 0;
}