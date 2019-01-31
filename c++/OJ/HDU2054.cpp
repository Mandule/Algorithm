#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;


int deal(string& str){
	int i,ans = 1;
	if(str[0]=='-'){
		ans = 0;
		str.erase(str.begin());
	}
	while(str[0]=='0' && str[1]!='.' && str.size()>1)
		str.erase(str.begin());
	if(str.find('.')!=string::npos)
		while(str[str.size()-1]=='0') str.erase(str.end()-1);
	if(str[str.size()-1] == '.')
		str.erase(str.end()-1);
	if(str == "0") ans =1;
	return ans;
}


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    string str1,str2;
    while(cin>>str1>>str2){
    	int a = deal(str1);
    	int b = deal(str2);
    	if(a==b && str1==str2) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
    return 0;
}