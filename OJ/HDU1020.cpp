#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;


string str;

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>str;
		str = str+"#";
		int num=1;
		for(int i=1;i<str.size();i++){
			if(str[i] != str[i-1]){
				if(num == 1) cout<<str[i-1];
				else cout<<num<<str[i-1];
				num=1;
			}
			else num++;
		}
		cout<<endl;
	}    
    return 0;
}