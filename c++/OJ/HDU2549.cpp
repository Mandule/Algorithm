#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long ll;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    int t;
    string str;
    cin>>n;
    while(n--){
    	cin>>str>>t;
    	int i=0;
    	while(str[i]!='.') i++;
    	while(t--) i++;
    	if(i>=str.size()) cout<<0<<endl;
    	else cout<<str[i]<<endl;
    }
    return 0;
}