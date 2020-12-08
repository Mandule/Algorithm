#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string str;
    while(getline(cin,str)){
    	if(str == "#") break;
    	string tmp;
    	getline(cin,tmp);
 	   	for(int i=0;i<str.size();i++){
 	   		int num=0;
 	   		int s = 0;
 	   		while( (s = tmp.find_first_of(str[i],s)) != -1){
 	   			s++;
 	   			num++;
 	   		}
 	   		cout<<str[i]<<" "<<num<<endl;
 	   	}
    }
    return 0;
}