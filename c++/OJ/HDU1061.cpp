#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;


int ans[10000];


int f(int num,int n){
	int ans = num%10;
	for(int i=0;i<n-1;i++){
		ans = (ans*num)%10;
	}
	return ans;
}



int main(){
	int n;
	cin>>n;
	while(n--){
		int num;
		cin>>num;

		int i;
		for(i=1;i<=num;i++){
			ans[i] = f(num,i);
			if(i!=1 && ans[1] == ans[i]) break;
		}
		ans[0] = ans[i-1];
		int k = num%(i-1);
		cout<<ans[k]<<endl;

	}    
    return 0;
}