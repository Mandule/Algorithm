#include <iostream>
using namespace std;

int main(){
	int now=-1;
	int next;
	int ans=0;
	int tmp;
	while(cin>>next){
		if(next==0) break;
		if(next==1)
			tmp = 1;
		if(next==2){
			if(now == -1 || now == 1)
				tmp = 2;
			else
				tmp += 2;
		}
		ans += tmp;
		now = next;
	}
	cout<<ans<<endl;
	return 0;
}
