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

map<string,int> Map;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string str;
    while(getline(cin,str) && str!="#"){
    	Map.clear();
    	stringstream ss(str);
    	int ans = 0;
    	while(ss>>str) Map[str]++;
    	cout<<Map.size()<<endl;
    }
    return 0;
}