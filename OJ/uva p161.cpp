#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int len = 32;
const int MAX_N = 10000+5;
char s[MAX_N];
int map[len][len];
int ans;

void draw(char* s,int& p,int x,int y,int len){
	char ch = s[p++];
	if(ch == 'p'){
		draw(s,p,x,y+len/2,len/2);
		draw(s,p,x,y,len/2);
		draw(s,p,x+len/2,y,len/2);
		draw(s,p,x+len/2,y+len/2,len/2);
	}else if(ch == 'f'){
		for(int i=x;i<x+len;i++)
			for(int j=y;j<y+len;j++)
				if(map[i][j]!=1){
					map[i][j] = 1;
					ans++;
				}
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		memset(map,0,sizeof(map));		
		ans = 0;
		for(int i=0;i<2;i++){
			cin>>s;
			int p =0;
			draw(s,p,0,0,len);
		}
		cout<<ans<<endl;
	}
	return 0;
}
