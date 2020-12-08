#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


int main(){
	char str[260];
	while(gets(str)){
		if(str[0] == '#') break;
		int len = strlen(str);
		int ans = 0;
		for(int i=0;i<len;i++){
			if(str[i] == ' ') continue;
			ans += (i+1)*(str[i]-'A'+1);
		}
		cout<<ans<<endl;
	}
	
}
