#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;


char str[105];
char max_c;
void p(char c){
	cout<<c;
	if(c==max_c) cout<<"(max)";
}


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    while(cin.getline(str,105)){
    	int n = strlen(str);
    	max_c = *max_element(str,str+n);
    	for_each(str,str+n,p);
    	cout<<endl;
    }
    return 0;
}