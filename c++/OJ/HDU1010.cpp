#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long ll;

char map[10][10];
int vis[10][10];

int n,m,T;
int sx,sy;
int dx,dy;

int go[][2]={
	-1,0,
	1,0,
	0,1,
	0,-1
};

bool dfs(int x,int y,int t){
	if(x == dx && y == dy && t == T) return true;
	for(int i=0;i<4;i++){
		int nx = x+go[i][0];
		int ny = y+go[i][1];
		int nt = t+1;

		if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if(nt > T) continue;
		if(vis[nx][ny] != -1) continue;
		if(map[nx][ny] == 'X') continue;
		if((nx+ny+dx+dy+T-nt)%2 == 1) continue;

		vis[nx][ny] = 1;
		if(dfs(nx,ny,nt)) return true;
		vis[nx][ny] = -1;
	}
	return false;
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	while(cin>>n>>m>>T && (n+m+T)){
 		memset(vis,-1,sizeof(vis));
 		for(int i=0;i<n;i++){
 			for(int j=0;j<m;j++){
 				cin>>map[i][j];
 				if(map[i][j]=='S'){sx=i;sy=j;}
 				else if(map[i][j]=='D'){dx=i;dy=j;}
 			}
 		}
 		if((sx+sy+dx+dy+T)%2 == 1){cout<<"NO"<<endl;continue;}
 		vis[sx][sy] = 1;
 		bool ans = dfs(sx,sy,0);
 		cout<<(ans ? "YES" : "NO")<<endl;
 	}

    return 0;
}