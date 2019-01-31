#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct state{
	int x,y,z;
	int t;
}tmp[1000];

int size;
queue<state> Q;
int maze[50][50][50];
int mark[50][50][50];
int go[][3]={
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1	
};

state creat(int x,int y,int z,int t){
	tmp[size].x = x;
	tmp[size].y = y;
	tmp[size].z = z;
	tmp[size].t = t;
	return tmp[size++];
}

void init(){
	while(!Q.empty()){
		Q.pop();
	}
	size = 0;
}

int BFS(int a,int b,int c,int T){
	while(!Q.empty()){
		state now = Q.front();Q.pop();
		if(now.t+1 > T) return -1;
		for(int i=0;i<6;i++){
			int nx = now.x+go[i][0];
			int ny = now.y+go[i][1];
			int nz = now.z+go[i][2];
			int nt = now.t+1;
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue;
			if(maze[nx][ny][nz]==1) continue;
			if(mark[nx][ny][nz]) continue;
			if(nx == a-1&&ny == b-1&&nz == c-1) return nt;
			state tmp = creat(nx,ny,nz,nt);
			Q.push(tmp);
			mark[nx][ny][nz] = true;
		}
	}
	return -1; 
}

int main(){
	int n;
	int a,b,c,T;
	cin>>n;
	while(n--){
		init();
		cin>>a>>b>>c>>T;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					cin>>maze[i][j][k];
					mark[i][j][k]=false;
				}
			}
		}
		state start = creat(0,0,0,0);
		mark[0][0][0] = true;
		Q.push(start);
		cout<<BFS(a,b,c,T)<<endl;
	}
} 
