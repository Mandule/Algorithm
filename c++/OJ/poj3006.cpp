#include <cstdio>
#include <iostream>
#define MAX_N 1000000
using namespace std;

bool isPrime[MAX_N+1];

void initPrime(){
	for(int i=0;i<=MAX_N;i++)
		isPrime[i] = true;
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2;i*i<=MAX_N;i++){
		if(isPrime[i]){
			for(int j=i*i;j<=MAX_N;j+=i){
				isPrime[j] = false;
			}
		}
	}
}

int main(){
	int a,b,n;
	initPrime();
	while(scanf("%d%d%d",&a,&b,&n)!=EOF){
		if(a==0 && b==0 && n==0) break;
		while(n){
			if(isPrime[a]) n--;
			a = a+b;
		}
		cout<<a-b<<endl;
	} 
}
