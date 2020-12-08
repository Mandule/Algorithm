#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <set>
using namespace std;



void miniStr(string& str){
	int i=0,j=1,k=0;
	int len = str.size();
	int tmp;
	while(i<len && j<len && k<len){
		tmp = str[(i+k)%len] - str[(j+k)%len];
		if(tmp==0) k++;
		else if(tmp>0){
			i = i+k+1;
			if(i==j) i++;
			k = 0;
		}
		else if(tmp<0){
			j = j+k+1;
			if(i==j) j++;
			k = 0;
		}
	}
	int s = min(i,j);
	str = (str+str).substr(s,str.size());
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    while(cin>>n){
    	set<string> Set;
    	while(n--){
    		string str;
    		cin>>str;
    		miniStr(str);
    		if(!Set.count(str)) Set.insert(str);
    	}
    	cout<<Set.size()<<endl;
    }
    return 0;
}