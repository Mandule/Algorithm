#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <map>
using namespace std;
typedef long long ll;


map<char,int> M1;
map<char,int> M2;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string str1,str2;
    while(cin>>str1>>str2){
    	M1.clear();
    	M2.clear();
    	bool ans =true;
    	for(int i=0;i<str1.size();i++)
    		M1[str1[i]]++;
    	for(int i=0;i<str2.size();i++){
    		M2[str2[i]]++;
    		if(M1[str2[i]] < M2[str2[i]]){
    			ans = false;
    			break;
    		}
    	}
    	cout<<(ans ? "yes" : "no")<<endl;
    }
    return 0;
}