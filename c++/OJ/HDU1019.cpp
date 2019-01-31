#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;


int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(void){
	int cas,n,x,ans;
	cin>>cas;
	while(cas--){
		cin>>n>>ans;
		for(int i=1;i<n;i++){
			cin>>x;
			ans=ans/gcd(ans,x)*x;
		}
		cout<<ans<<endl;
	}
	return 0;
}