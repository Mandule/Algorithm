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
    int n;
    cin>>n;
    getchar();
    while(n--){
    	string str;
    	bool ans=true;
    	getline(cin,str);
    	if(str[0] <='9' && str[0]>='0') ans = false;
    	else
    		for(int i=1;i<str.size();i++) if(str[i] == ' '){
    			ans = false;
    			break;
    		}
    	cout<<(ans?"yes":"no")<<endl;
    }
    return 0;
}