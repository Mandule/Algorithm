#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;




int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a==0&&b==0) break;
		int ans=1;
		while(b>0){
			if(b%2==1){
				ans *= a;
			}	
			b = b/2;
			a = a*a;
		}
		cout<<ans;
	}	
	return 0;
}
