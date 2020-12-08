#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    char c;
    string str;
 	while(cin>>c>>str){
 		int n=0;
 		c = tolower(c);
 		for(int i=0;i<str.size();i++)
 			if(str[i] == c || str[i] == char(c-32)) n++;
 		cout<<fixed<<setprecision(5)<<double(n)/str.size()<<endl;
 	}

    return 0;
}