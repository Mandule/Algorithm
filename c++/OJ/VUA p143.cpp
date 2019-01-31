#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10000+5;
int last,cur,my_next[maxn];
char s[maxn];


int main(){
	while(scanf("%s",s+1)==1){
		int n = strlen(s+1);
		last = cur = 0;
		my_next[0] = 0;
		for(int i=1;i<=n;i++){
			char ch = s[i];
			if(ch=='[') cur = 0;
			else if(ch == ']') cur = last;
			else{
				my_next[i] = my_next[cur];
				my_next[cur] = i;
				if(cur==last) last = i;
				cur = i;
			}
		}
		for(int i=my_next[0];i!=0;i=my_next[i]){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
