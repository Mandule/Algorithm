#include <cstdio>
#include <iostream>
using namespace std;



int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int tmp;
		if(a<b){
			tmp = a;
			a = b;
			b = tmp;
		}
		while(b!=0){
			tmp = b;
			b = a%b;
			a = tmp;
		}
		cout<<a<<endl;
	}
	
	return 0;
}
