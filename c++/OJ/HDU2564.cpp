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
 	string str;
 	cin>>n;
 	getchar();
 	while(n--){
 		getline(cin,str);
 		stringstream ss(str);
 		string ans;
 		while(ss>>str){
 			ans += toupper(str[0]);
 		}
 		cout<<ans<<endl;
 	}   
    return 0;
}