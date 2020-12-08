#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int ring[20];
bool mark[20];
int n;

bool isPrime(int x){
	for(int i=2;i <= sqrt(x);i++){
		if(x%i == 0) return false;
	}
	return true;
}

void init(){
	for(int i=0;i<20;i++){
		mark[i]=false;	
	}
}

void DFS(int num){
	if(num>1) 
		if(!isPrime(ring[num]+ring[num-1]))
			return;
	if(num==n){
		if(!isPrime(ring[num]+ring[1]))
			return;
		for(int i=1;i<=n;i++){
			cout<<ring[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=2;i<=n;i++){
		if(!mark[i]){
			mark[i]=true;
			ring[num+1]=i;
			DFS(num+1);
			mark[i]=false;
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		ring[1]=1;
		mark[1]=true;
		DFS(1);
	}
	return 0;
}
