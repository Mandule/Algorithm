#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue> 
using namespace std;

struct state{
	int x,y,z;
	int t;
};

queue<state> Q;
int go[][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
}; 

int maze[50][50][50];
int mark[50][50][50];


void init(int a,int b,int c){
	while(!Q.empty()) Q.pop();
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			for(int k=0;k<c;k++){
				cin>>maze[i][j][k];
				mark[i][j][k] = 0;
			}
		}
	}
	mark[0][0][0] = 1;
	state start;
	start.x = 0;
	start.y = 0;
	start.z = 0;
	start.t = 0;
	Q.push(start);
}

int BFS(int a,int b,int c,int t){
	while(!Q.empty()){
		state now = Q.front();
		Q.pop();
		if(now.x == a-1 && now.y == b-1 && now.z == c-1 && now.t <= t) return now.t;
		state next;
		for(int i=0;i<6;i++){
			next.x = now.x+go[i][0];
			next.y = now.y+go[i][1];
			next.z = now.z+go[i][2];
			next.t = now.t+1;
			if(next.x<0 || next.x>a-1 || next.y<0 || next.y>b-1 || next.z<0 || next.z>c-1) continue;
			if(maze[next.x][next.y][next.z]==1 || mark[next.x][next.y][next.z]==1) continue;
			if(next.t > t) continue;
			Q.push(next);
		}
	}
	return -1; 
}


int main(){
	int a,b,c,t;
	while(scanf("%d%d%d%d",&a,&b,&c,&t)!=EOF){
		init(a,b,c);
		cout<<BFS(a,b,c,t)<<endl;
	}	
	
	return 0;
}
 
