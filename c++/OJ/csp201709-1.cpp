#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int ans =0;
		while(n >= 50){
			ans += 7;
			n -= 50;
		}
		while(n >= 30){
			ans += 4;
			n -= 30;
		}
		ans += n/10;
		cout<<ans<<endl;
	}

	return 0;
}