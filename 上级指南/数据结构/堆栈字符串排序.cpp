#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> s;
char str[110];
char ans[110];

int main(){
	while(scanf("%s",&str)!=EOF){
		int i;
		for(i=0;str[i]!='\0';i++){
			if(str[i] == '('){
				s.push(i);
				ans[i]=' ';
			}
			else if(str[i] == ')'){
				if(!s.empty()){
					ans[i]=' ';
					s.pop();
				}
				else{
					ans[i]='?';
				}
			}
			else{
				ans[i]=' ';
			}
		}
		ans[i]='\0';
		while(!s.empty()){
			ans[s.top()]='$';
			s.pop();
		}
		puts(str);
		puts(ans);
	}	
	return 0;
}
