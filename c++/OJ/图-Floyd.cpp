#define LOCAL
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int edge[105][105];


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while(cin>>n>>m && (n+m) ){
		memset(edge,-1,sizeof(edge));
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			edge[a][b] = edge[b][a] = c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(edge[i][k] == -1 || edge[k][j] == -1) continue;
					if(edge[i][j] == -1 || edge[i][k]+edge[k][j]<edge[i][j]){
						edge[i][j] = edge[i][k]+edge[k][j];
					}
				}
			}
		}
		cout<<edge[1][n]<<endl;
	}
	return 0;
}