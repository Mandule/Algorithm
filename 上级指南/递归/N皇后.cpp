#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int queen[15];
int n;

bool canPlace(int k){
	for(int i=1;i<k;i++){
		if(queen[i]==queen[k] || abs(i-k)==abs(queen[i]-queen[k]))
			return false;	
	}
	return true;
}

void QUEEN(int s){
	if(s>1){
		if(!canPlace(s))
			return;
	}
	if(s==n){
		for(int i=1;i<=n;i++){
			cout<<queen[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		queen[s+1] = i;
		QUEEN(s+1);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			queen[1]=i;
			QUEEN(1);
		}
	}
	return 0;
} 
