#include <cstdio>
#include <iostream>
using namespace std;

int buf[50];

int main(){
	int m;
	long long A,B;
	while(scanf("%d",&m)!=EOF){
		if(m==0)break;
		scanf("%lld%lld",&A,&B);
		long long sum = A+B;
		int size=0;
		while(sum>0){
			buf[size++] = sum%m;
			sum = sum/m;
		}
		for(int i=size-1;i>-1;i--){
			cout<<buf[i];
		}
		cout<<endl;
	}
	return 0;
} 
