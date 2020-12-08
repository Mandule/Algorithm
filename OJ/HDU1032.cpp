#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAX_N = 1000005;
int num[MAX_N];

int f(int i){
	int tmp = i;
	int n=1;
	while(tmp != 1){
		if(tmp%2 != 0) tmp = 3*tmp+1;
		else tmp /= 2;
		n++;
	}
	return n;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
    	int ans = 0;
    	bool exchange = false;
    	if(a>b){
    		exchange = true;
    		swap(a,b);
    	}
    	for(int i=a;i<=b;i++){
    		int tmp = f(i);
    		if(ans<tmp) ans = tmp;
    	}
    	if(!exchange)
    		cout<<a<<" "<<b<<" "<<ans<<endl;
    	else
    		cout<<b<<" "<<a<<" "<<ans<<endl;
    }    
    return 0;
}