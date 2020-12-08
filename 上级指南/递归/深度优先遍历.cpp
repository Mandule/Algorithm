#include <cstdio>
#include <iostream>
using namespace std;
int N,M,T;
int Dx,Dy;
int Sx,Sy;

char maze[10][10];

int go[][2]={
	1,0,
	-1,0,
	0,1,
	0,-1
};

void init(){
	for(int i=1;i<=N;i++){
		cin>>maze[i]+1;
		for(int j=1;j<=M;j++){
			if(maze[i][j]=='D'){
				Dx=i;
				Dy=j;
			}
			if(maze[i][j]=='S'){
				Sx=i;
				Sy=j;
			}
		}
	}
}

bool BFS(int x,int y,int t){
	cout<<x<<" "<<y<<" "<<t<<endl;
	for(int i=0;i<4;i++){
		int nx = x+go[i][0];
		int ny = y+go[i][1];
		int nt = t+1;
		if(nx<1||nx>N||ny<1||ny>M) continue;
		if(maze[nx][ny]=='X') continue;
		if(maze[nx][ny]=='D'){
			if(nt==T) return true;
			continue;
		}
		maze[nx][ny]='X';
		if(BFS(nx,ny,nt))
			return true;
		maze[nx][ny]='.';
	}
	return false;
}


int main(){
	while(scanf("%d%d%d",&N,&M,&T)!=EOF){
		init();
		maze[Sx][Sy]='X';
		cout<<"+++"<<Dx<<Dy<<endl;
		if(BFS(Sx,Sy,0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
