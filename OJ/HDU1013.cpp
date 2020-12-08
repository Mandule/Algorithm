#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	string n;
	int t;
	while(cin>>n){
		if(n=="0") break;
		while(n.size()>1){
			t=0;
			for(int i=0;i<n.size();i++){
				t=t+(n[i]-'0');
			}
			n=to_string(t);
		}
		cout<<n<<endl;
	}
}

