#include <cstdio>
#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

int A[1001];
int B[1001];
int n;

void print_subset(int cur){
	if(cur==n){
		for(int i=0;i<n;i++){
			if(B[i]==1) cout<<A[i]<<" ";
		}
		cout<<endl;
		return;
	}
	B[cur] = 1;
	print_subset(cur+1);
	B[cur] = 0;
	print_subset(cur+1); 
}


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			A[i] = i;
		memset(B,0,sizeof(B));
		print_subset(0);
	}
	return 0;
}
