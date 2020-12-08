#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1000000+5;

int f[MAX_N];

int main(){
	f[1] = 1;
	f[2] = 2;
	int i;
    for(i=3;i<MAX_N;i++){
    	f[i] = (f[i-1]+f[i-2])%3;
    	if(f[i]==2 && f[i-1]==1) break;
    }
    f[0] = f[i-2];
    int T = i-2;
    int n;
	while(cin>>n){
		n = (n+1)%T;
		if(f[n] == 0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
    return 0;
}