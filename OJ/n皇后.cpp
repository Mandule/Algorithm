#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_N = 20;
int queen[MAX_N];
int n;
int ans;

bool canPlace(int cur,int col){
	for(int i=0;i<cur;i++){
		int tmp1 = abs(cur-i);
		int tmp2 = abs(col-queen[i]);
		if(tmp2==0 || tmp1 == tmp2) return false;
	}
	return true;
}

void Queen(int cur){
	if(cur==n){
		ans++;
		for(int i=0;i<n;i++)
			cout<<queen[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(canPlace(cur,i)){
			queen[cur] = i;
			Queen(cur+1);
		}
	}
}


int main(){
	while(scanf("%d",&n)!=EOF){
		ans = 0;
		Queen(0);		
	}
} 


