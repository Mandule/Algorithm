#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;
typedef long long ll;

	int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string str;
	string ans;
    while(getline(cin,str)){
    	transform(str.begin(),str.end(),str.begin(),::tolower);
    	cout<<str<<endl;
    }
    return 0;
}