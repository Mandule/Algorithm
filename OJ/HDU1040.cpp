#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;
typedef long long ll;

int n;
string str;
set<int> s;

int main(){
    cin>>n;
    getchar();
    while(n--){
    	s.clear();
    	getline(cin,str);
    	stringstream ss(str);
    	int tmp;
    	while(ss>>tmp){
    		if(!s.count(tmp)) s.insert(tmp);
    	}
    	for(auto i = s.begin();i!=s.end();i++){
    		if(next(i) != s.end())cout<<*i<<" ";
    		else cout<<*i<<endl;
    	}
    }
    return 0;
}