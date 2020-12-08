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
 	while(cin>>str1 && str1!="#"){
 		cin>>str2;
 		int i=0;
 		int ans =0 ;
 		while(1){
 			i = str1.find(str2,i);
 			if(i==-1) break;
 			ans++;
 			i = i+str2.size();
 		}
 		cout<<ans<<endl;
 	}   
    return 0;
}