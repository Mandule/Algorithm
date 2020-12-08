#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct state{
	int n;
	int m;
	int s;
	int t;
};



int capN,capM,capS;
int mark[101][101][101];
queue<state> Q;


int go[][3]={
	-1,1,0,
	-1,0,1,
	1,-1,0,
	0,-1,1,
	1,0,-1,
	0,1,-1
}; 

void init(int capN,int capM,int capS){
	while(!Q.empty()) Q.pop();
	for(int i=0;i<=capN;i++)
		for(int j=0;j<=capM;j++)
			for(int k=0;k<=capS;k++)
				mark[i][j][k] = 0;
	state start;
	start.n = 0;
	start.m = 0;
	start.s = capS;
	start.t = 0;
	mark[0][0][capS] = 1;
	Q.push(start);
}

void pour(state now,int n,int m,int s){
	state next;
	if(n==-1 && now.n!=0){
		if(m==1){
			if(now.n+now.m > capM){
				next.m = capM;
				next.n = now.n+now.m-capM;
			}else{
				next.m = now.n+now.m;
				next.n = 0;
 			}
			next.s = now.s;
		}else
		if(s==1){
			if(now.n+now.s > capS){
				next.s = capS;
				next.n = now.n+now.s-capS;
			}else{
				next.s = now.n+now.s;
				next.n = 0;
			}
			next.m = now.m;
		}
	}else
	if(m==-1 && now.m!=0){
		if(n==1){
			if(now.n+now.m > capN){
				next.n = capN;
				next.m = now.n+now.m-capN;
 			}else{
 				next.n = now.n+now.m;
 				next.m = 0;
			 }
			 next.s = now.s;
		}else
		if(s==1){
			if(now.s+now.m > capS){
				next.s = capS;
				next.m = now.s+now.m-capS;
			}else{
				next.s = now.s+now.m;
				next.m = 0;
			}
			next.n = now.n;
		}
	}else
	if(s==-1 && now.s!=0){
		if(n==1){
			if(now.s+now.n>capN){
				next.n = capN;
				next.s = now.s+now.n-capN;
			}else{
				next.n = now.s;
				next.s = 0;	
			}
			next.m = now.m;
		}else
		if(m==1){
			if(now.s+now.m>capM){
				next.m = capM;
				next.s = now.m+now.s-capM;
			}else{
				next.m = now.s;
				next.s = 0;
			}
			next.n = now.n;
		}
	}else return; 
	if(mark[next.n][next.m][next.s]==1) return;
	next.t = now.t+1;
	mark[next.n][next.m][next.s] = 1;
	Q.push(next);
}

int	BFS(){
	while(!Q.empty()){
		state now = Q.front();
		Q.pop();
		if(now.n == capS/2 && now.s == capS/2) return now.t;
		if(now.n == capS/2 && now.m == capS/2) return now.t;
		if(now.m == capS/2 && now.s == capS/2) return now.t;
		for(int i=0;i<6;i++){
			pour(now,go[i][0],go[i][1],go[i][2]);
		}
	}
}


int main(){
	while(scanf("%d%d%d",&capS,&capN,&capM)!=EOF){
		if(capS%2 ==1){
			cout<<"NO"<<endl;
			continue;
		}
		init(capN,capM,capS);
		cout<<BFS()<<endl;
	}
	return 0;
}
