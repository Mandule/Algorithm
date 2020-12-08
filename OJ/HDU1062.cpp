#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    getchar();
    while(n--){
    	string str;
    	getline(cin,str);
    	stringstream ss(str);
    	int i=1;
    	while(ss>>str){
    		if(i!=1) cout<<" ";
    		for(int i=str.size()-1;i>=0;i--) cout<<str[i];
    		i++;
    	}
    	if(n>0) cout<<endl;
    }

    return 0;
}