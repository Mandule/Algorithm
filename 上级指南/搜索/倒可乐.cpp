#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct state{
	int s,n,m;
	int t;
}statics[100000];
int size;
queue<state> Q;
bool mark[101][101][101];
state creat(int s,int n,int m,int t){
	statics[size].s = s;
	statics[size].n = n;
	statics[size].m = m;
	statics[size].t = t;
	return statics[size++]; 
}
void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<101;k++){
				mark[i][j][k]=false;
			}
		}
	} 
	while(!Q.empty()){
		Q.pop();
	}
	size;
}
void pour(int &a,int &b,int sa,int sb){
	if(a==0) return;
	if(sb >= a+b){
		b=b+a;
		a=0;
	}
	else{
		a=a-(sb-b);
		b=sb;
	}
}

bool isHalf(state tmp,int S){
	int s = tmp.s;
	int n = tmp.n;
	int m = tmp.m;
	int h = S/2;
	if(s==h&&n==h) return true;
	if(s==h&&m==h) return true;
	if(n==h&&m==h) return true;
	return false;
}

int BFS(int S,int N,int M){
	while(!Q.empty()){
		state now = Q.front();
		Q.pop();
		int t=now.t;
		
		int s=now.s,n=now.n,m=now.m;
		pour(s,n,S,N);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		
		s=now.s;n=now.n;m=now.m;
		pour(s,m,S,M);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		
		s=now.s;n=now.n;m=now.m;
		pour(n,m,N,M);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		s=now.s;n=now.n;m=now.m;
		pour(n,s,N,S);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		s=now.s;n=now.n;m=now.m;
		pour(m,s,M,S);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		s=now.s;n=now.n;m=now.m;
		pour(m,n,M,N);
		if(!mark[s][n][m]){
			state tmp = creat(s,n,m,t+1);
			if(isHalf(tmp,S))	return tmp.t;
			Q.push(tmp);
			mark[s][n][m]=true;
		}
		
	}
	return -1;
}

int main(){
	int S,N,M;
	while(scanf("%d%d%d",&S,&N,&M)!=EOF){
		if(S==0 && N==0 && M ==0) break;
		if(S%2 != 0){
			cout<<"NO"<<endl;
			continue;
		}
		init();
		state start = creat(S,0,0,0);
		mark[S][0][0]=true;
		Q.push(start);
		int t= BFS(S,N,M);
		if(t==-1) cout<<"NO"<<endl;
		else cout<<t<<endl;
	}
	return 0;
}
