#include <cstdio>
#include <iostream>
using namespace std;

char map[101][101];
int mark[101][101];
int n,m;
int go[8][2]={
	1,0,
	-1,0,
	0,1,
	0,-1,
	1,1,
	1,-1,
	-1,1,
	-1,-1
};


void DFS(int x,int y){
	int nx,ny;
	for(int i=0;i<8;i++){
		nx = x+go[i][0];
		ny = y+go[i][1];
		if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if(mark[nx][ny] == 1) continue;
		if(map[nx][ny] == '*') continue;
		mark[nx][ny] = 1;
		DFS(nx,ny);
	}		
}


int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>map[i][j];
				mark[i][j]=0;
			}
		int ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]=='@' && mark[i][j]==0 ){
					DFS(i,j);
					ans++;		
				}
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
