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
    int i=1;
    while(n--){
    	string str;
    	getline(cin,str);
    	cout<<"String #"<<i++<<endl;
    	for(int i=0;i<str.size();i++){
    		if(str[i]=='Z') cout<<'A';
    		else cout<<char(str[i]+1);
    	}
    	cout<<endl<<endl;;
    }
    return 0;
}