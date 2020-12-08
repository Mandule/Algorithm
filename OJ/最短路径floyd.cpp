#include <cstdio>
#include <iostream>
#define N 101
using namespace std;



int cost[N][N];


void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cost[i][j] = -1;
		cost[i][i]=0;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0) break;
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			cost[a][b] = cost[b][a] = c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(cost[i][k] ==-1 || cost[k][j]==-1) continue;
					if(cost[i][j] ==-1 || cost[i][k]+cost[j][k] < cost[i][j])
						cost[i][j] = cost[i][k]+cost[j][k];
				}
			}
		}
		cout<<cost[1][n]<<endl;
	}	
	
	return 0;
}
