#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


struct Move{
	int a;
	int b;
}m[201]; 

int c[201];

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=200;i++) c[i] = 0;
		for(int i=0;i<n;i++){
			cin>>m[i].a>>m[i].b;
			if(m[i].a>m[i].b) swap(m[i].a,m[i].b);
			if(m[i].a%2==1) m[i].a += 1;
			if(m[i].b%2==1) m[i].b += 1;
			for(int j=m[i].a/2;j<=m[i].b/2;j++)
				c[j]++;
		}
		int ans=0;
		for(int i=1;i<=200;i++)
			ans = max(c[i],ans);
		cout<<ans*10<<endl;
	}
}
