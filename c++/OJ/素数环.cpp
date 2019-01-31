#include <cstdio>
#include <iostream>
using namespace std;

int n;
int ring[17];
int mark[17];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int k){
	for(int i=0;i<13;i++)
		if(k==prime[i]) return true;
	return false;
}

void P(int k){
	if(k == n && isPrime(ring[1]+ring[k])){
		for(int i=1;i<=n;i++)
			cout<<ring[i]<<" ";
		cout<<endl;
	}
	for(int i=2;i<=n;i++){
		if(mark[i]==0 && isPrime(i+ring[k])){
			ring[k+1] = i; 
			mark[i] = 1;
			P(k+1);
			mark[i] = 0;
		}
	}	
}


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			mark[i] = 0;
		ring[1] = 1;
		mark[1] = 1;
		P(1);
	}
} 
