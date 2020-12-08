#define LOCAL
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    string str;
    while(getline(cin,str)){
    	stringstream ss(str);
    	bool first = true;
    	while(ss>>str){
    		if(!first) cout<<" ";
    		cout<<char(toupper(str[0]));
    		for(int i=1;i<str.size();i++) cout<<str[i];
    		first = false;
    	}
    	cout<<endl;
    }	
    return 0;
}