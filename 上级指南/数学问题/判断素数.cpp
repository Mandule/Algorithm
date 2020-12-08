#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		bool ans = true;
		int n = (int)sqrt(x)+1;
		for(int i=2;i<n;i++){
			if(x%i == 0){
				ans=false;
				break;
			}
		}
		if(x<=1)ans=false;
		cout<<(ans?"yes":"no")<<endl;
	}
	
	return 0;
} 
