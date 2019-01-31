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
    string str1,str2;
    while(cin>>str1>>str2){
    	str1 = str1+str1;
    	if(str1.find(str2)!=string::npos) cout<<"yes"<<endl;
    	else cout<<"no"<<endl;
    }
    return 0;
}