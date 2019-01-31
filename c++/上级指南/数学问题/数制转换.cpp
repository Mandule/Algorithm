#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char str[20];

int main(){
	int a,b;
	while(scanf("%d%s%d",&a,&str,&b)!=EOF){
		int length = strlen(str);
		int ans = 0;
		for(int i=0;i<length;i++){
			char c = str[i];
			int tmp;
			if(c>='0' && c<='9'){
				tmp = c-'0';
			}
			else if(c>='a' && c<='z'){
				tmp = c-'a'+10;
			}
			else{
				tmp = c-'A'+10;
			}
			ans = (ans+tmp)*a;
		}
		ans /= a;
		
		int size=0;
		while(ans>0){
			int tmp;
			tmp = ans%b;
			ans /= b;
			if(tmp>=10){
				str[size] = char('A'+tmp-10);
			}
			else{
				str[size] = char('0'+tmp);
			}
			size++;
		}
		for(int i=size-1;i>-1;i--){
			cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
} 
