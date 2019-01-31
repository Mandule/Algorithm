#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <climits>
#include <stack>
using namespace std;

int n,m;
int dx,dy;
char maze[100][100];
int vis[100][100];
int min_t;
bool exist;

void init(){
	min_t = INT_MAX;
	dx = n-1;
	dy = m-1;
	memset(vis,-1,sizeof(vis));
	vis[0][0] = 1;
	exist = false;
}

int go[][2]={
	-1,0,
	1,0,
	0,1,
	0,-1
};


void dfs(int x,int y,int t){
	if(x == dx && y == dy && t<min_t){min_t = t;exist = true;return;}
	for(int i=0;i<4;i++){
		int nx = x+go[i][0];
		int ny = y+go[i][1];
		int nt = t+1;

		if(nx <0 || nx>n-1 || ny<0 || ny>m-1) continue;
		if(vis[nx][ny] == 1) continue;
		if(maze[nx][ny] == 'X') continue;
		if(maze[nx][ny]<='9' && maze[nx][ny]>='0') nt += maze[nx][ny]-'0';
		if(nt >= min_t) continue;

		vis[nx][ny] = 1;
		dfs(nx,ny,nt);
		vis[nx][ny] = -1;
	}
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m){
    	for(int i=0;i<n;i++)
    		cin>>maze[i];
    	init();
    	dfs(0,0,0);
    	if(!exist){cout<<"God please help our poor hero."<<endl;continue;}
    	cout<<"It takes "<<min_t<<" seconds to reach the target position, let me show you the way."<<endl;
    }
    return 0;
}