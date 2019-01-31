#define LOCAL
#include <cstdio>
#include <cstdlib>
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
    int n;
    cin>>n;
    getchar();
    while(n--){
    	string str1,str2;
    	string tmp;
    	getline(cin,tmp);
    	while(1){
    		getline(cin,tmp);
    		if(tmp == "END") break;
    		if(tmp.empty()) str1 +="\n";
    		str1 += tmp;
    	}
    	getline(cin,tmp);
    	while(1){
    		getline(cin,tmp);
    		if(tmp == "END") break;
    		if(tmp.empty()) str2 +="\n";
    		str2 += tmp;
    	}
    	if(str1 == str2) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
    return 0;
}