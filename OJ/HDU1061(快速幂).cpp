#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;


int solve(int n){
	int ans = 1;
	int a=n%10,b=n;
	while(b!=0){
		if(b%2==1){
			ans *= a;
			ans %= 10;
		}
		b /=2;
		a *= a;
		a %= 10;
	}
	return ans;
}

int main(){
    int N;
    cin>>N;
    while(N--){
    	int n;
    	cin>>n;
    	cout<<solve(n)<<endl;
    }
    return 0;
}