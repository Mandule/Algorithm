#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int buf[10];

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int n=0,tmp=0;
		while(a>0){
			buf[n++] = a%10;
			a /= 10;
		}
		while(b>0){
			tmp += b%10;
			b /= 10;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans += buf[i]*tmp;
		}
		cout<<ans<<endl;		
	}
	
	return 0;
} 
