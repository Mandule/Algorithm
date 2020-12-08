#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int A[1001];
 
void solve(int n,int cur){
	if(cur == n){
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}
	else for(int i=1;i<=n;i++){
		int ok =1;
		for(int j=0;j<cur;j++)if(A[j] == i){
			ok = 0;
		}
		if(ok){
			A[cur] = i;
			solve(n,cur+1);
		}
	}
}

void init(int n){
	for(int i=0;i<n;i++)
		A[i] = i+1;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(A,0,sizeof(A));
		solve(n,0);
	}
	return 0;
}
