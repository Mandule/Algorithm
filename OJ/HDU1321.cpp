#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
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
    	string str;
    	getline(cin,str);
    	reverse(str.begin(),str.end());
    	cout<<str<<endl;
    }	
    return 0;
}