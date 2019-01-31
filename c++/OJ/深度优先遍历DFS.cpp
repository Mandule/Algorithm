#include <cstdio>
#include <iostream>
using namespace std;

char map[10][10];
int  mark[10][10];
int N,M,T;
int Sx,Sy;
int Dx,Dy;

struct state{
	int x;
	int y;
	int t;
	
};

int go[][2]={
	-1,0,
	1,0,
	0,-1,
	0,1
};

void initMap(int N,int M){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			cin>>map[i][j];
			if(map[i][j] == 'S'){
				Sx = i;
				Sy = j;
			}
			if(map[i][j] == 'D'){
				Dx = i;
				Dy = j;
			}
			mark[i][j]=0;
		}
}

bool DFS(state now){
	if(now.x==Dx && now.y==Dy && now.t == T) return true;
	bool ans = false;
	for(int i=0;i<4;i++){
		state next;
		next.x = now.x+go[i][0];
		next.y = now.y+go[i][1];
		next.t = now.t+1;
		if(next.x<1 || next.x >N || next.y<1 || next.y>M) continue;
		if(mark[next.x][next.y] == 1) continue;
		if(map[next.x][next.y]=='X') continue ;
		if(next.t > T) continue;
		mark[next.x][next.y] = 1;
		ans = DFS(next);
		if(ans==true) break;
		mark[next.x][next.y] = 0;
	}
	return ans;
}


int main(){
	while(scanf("%d%d%d",&N,&M,&T)!=EOF){
		initMap(N,M);
		state start;
		start.x = Sx;
		start.y = Sy;
		start.t = 0;
		cout<<DFS(start)<<endl;;
	}
	
	return 0;
} 
