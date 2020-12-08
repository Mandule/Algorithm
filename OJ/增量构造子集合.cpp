#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std; 

int A[1001];
int n;

void print_subset(int cur){
	for(int i=0;i<cur;i++){
		cout<<A[i]<<" ";
		if(i==cur-1) cout<<endl;
	}
	int s = cur ? A[cur-1]+1 : 0;
	for(int i=s;i<=n;i++){
		A[cur] = i;
		print_subset(cur+1);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			A[i] = i+1;
		print_subset(0);
	}
	return 0;
}
