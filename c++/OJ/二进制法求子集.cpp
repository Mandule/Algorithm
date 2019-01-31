#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

void print_subset(int cur){
	for(int i=0;i<n;i++){
		if(cur & 1<<i) cout<<i<<" ";
	}
	cout<<endl;
}


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i< (1<<n) ;i++)
			print_subset(i);
	}
}










