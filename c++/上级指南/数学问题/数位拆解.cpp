#include <cstdio>
#include <iostream>
using namespace std;

int buf1[20];
int buf2[20];

int main(){
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){
		int s1=0,s2=0;
		int ans=0;
		while(x>0){
			buf1[s1++] = x%10;
			x = x/10;
		}
		while(y>0){
			buf2[s2++] = y%10;
			y = y/10;
		}
		for(int i=0;i<s1;i++){
			for(int j=0;j<s2;j++){
				ans += buf1[i]*buf2[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
