#include <cstdio>
#include <iostream>
using namespace std;


bool solve(int &w){
	int w1,d1,w2,d2;
	bool b1=true,b2=true;
	cin>>w1>>d1>>w2>>d2;
	if(w1==0) b1 = solve(w1);
	if(w2==0) b2 = solve(w2);
	w = w1+w2;
	return b1 && b2 && (d1*w1 == d2*w2);
}


int main(){
	int n;
	cin>>n;
	while(n--){
		int W;
		if(solve(W)) cout<<"yes\n";
		else cout<<"no\n";
 
	}	
	return 0;
} 
