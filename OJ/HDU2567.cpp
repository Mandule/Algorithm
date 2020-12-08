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
    int n;cin>>n;getchar();
    string str1,str2;
    while(n--){
    	getline(cin,str1);
    	getline(cin,str2);
    	str1.insert(str1.size()/2,str2);
    	cout<<str1<<endl;
    }
    return 0;
}