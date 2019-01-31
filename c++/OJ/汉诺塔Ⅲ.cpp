#include <cstdio>
#include <iostream>

using namespace std;

long long H(int n){
	if(n==1) return 2;
	return 3*H(n-1)+2;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		cout<<H(n)<<endl;
	}
	return 0;
}
