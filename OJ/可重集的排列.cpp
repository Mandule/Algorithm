#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int A[1001];
int p[1001]; 

void solve(int n,int cur){
	if(cur == n){
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}
	else for(int i=0;i<n;i++)if(!i || p[i]!=p[i-1]){
		int c1=0,c2=0;
		for(int j=0;j<cur;j++)if(A[j] == p[i]) c1++;
		for(int j=0;j<n;j++)if(p[j] == p[i]) c2++;
		if(c1<c2){
			A[cur] = p[i];
			solve(n,cur+1);
		}
	}
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(A,0,sizeof(A));
		for(int i=0;i<n;i++) cin>>p[i];	
		sort(p,p+n);
		solve(n,0);
	}
	
}
