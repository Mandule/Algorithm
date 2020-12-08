#include <cstdio>
#include <iostream>
using namespace std;

int A,B,n;
int ans[1000];


int main(){
	ans[1] = 1;
	ans[2] = 1;
	while(cin>>A>>B>>n && A && B &&n){
		int i;
		for(i=3;i<1000;i++){
			ans[i] = (A*ans[i-1]+B*ans[i-2])%7;
			if(ans[i] == 1 && ans[i-1] ==1) break;
		}
		n = n%(i-2);
		ans[0] = ans[i-2];
		cout<<ans[n]<<endl;
	}
}
