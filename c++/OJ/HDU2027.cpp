#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<char,int> Map;

char ch[5]={'a','e','i','o','u'};

void op(char c){
	if(Map.count(c)) Map[c]++;
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    getchar();
    string str;
    while(n--){
    	getline(cin,str);
    	for(int i=0;i<5;i++) Map[ch[i]] = 0;
    	for_each(str.begin(),str.end(),op);
    	for(int i=0;i<5;i++) cout<<ch[i]<<":"<<Map[ch[i]]<<endl;
    	if(n!=0) cout<<endl;
    }
    return 0;
}