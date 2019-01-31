#include <cstdio>
#include <iostream>
using namespace std;



int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int tmp,ans;
		if(a<b){
			tmp = a;
			a = b;
			b = tmp;
		}
		ans = a*b;
		while(b!=0){
			tmp = b;
			b = a%b;
			a = tmp;
		}
		ans = ans/a;
		cout<<ans<<endl;
	}
	
	return 0;
}
