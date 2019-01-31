#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;


bool isDigit(char c){
	if( c<='9' && c>='0') return true;
	else return false;
}


void outThe(int num){
	cout<<char('A'+num-1);
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n;cin>>n;
    while(n--){
    	string str;cin>>str;
    	int num=0;
    	int i=0;
    	while(i<str.size()){
    		if(isDigit(str[i])){
    			while(isDigit(str[i]))
    				num = num*10 + str[i++]-'0';
    			outThe(num);
    			num = 0;
    		}
    		if(str[i] == '#') cout<<' ';
    		i++;
    	}
    	cout<<endl;
    }
    return 0;
}