#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

char str[101];
char ans[101];

stack<int> S;

int main(){
	while(scanf("%s",str)!=EOF){
		for(int i=0;i<strlen(str);i++){
			if(str[i] == '('){
				S.push(i);		
				ans[i] = ' ';
			}
			else if(str[i] == ')'){
				if(S.empty()) ans[i] = '?';
				else{
					S.pop();
					ans[i] = ' ';
				}
			}
			else{
				ans[i] = ' ';
			}
		}
		while(!S.empty()){
			ans[S.top()]  = '$';
			S.pop();
		}
		printf("%s\n",str);
		printf("%s\n",ans);
	}
	return 0;
}
