#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int ans[50];

int main(){
	int m;
	long long a,b;
	while(scanf("%d%lld%lld",&m,&a,&b)!=EOF){
		a = a+b;
		int n=0;
		while(a>0){
			ans[n++] = a%m;
			a /=m;
		}
		for(int i=n-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
} 
