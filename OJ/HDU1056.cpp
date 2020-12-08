#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const double MIN_VALUE = 1e-8;


int main(){
    double n;
    while(scanf("%lf",&n)!=EOF){
    	if(fabs(n)<MIN_VALUE) break;
    	int ans = 0;
    	while(n>0){
    		ans++;
    		n -= 1/double(ans+1);
    	}
    	cout<<ans<<" card(s)"<<endl;
    }    
    return 0;
}