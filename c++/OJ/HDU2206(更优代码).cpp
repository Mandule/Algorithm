#include<stdio.h>
#include<string.h>
int main(){
	int i,k,flag,cnt;
	char a[100];
	while(gets(a)){
		k=flag=cnt=0;
		for(i=0;i<strlen(a);i++){
			if(a[i]>='0'&&a[i]<='9'){
				k=k*10+a[i]-'0';
				if(k>255){
					flag=1;
					break;
				}
			}
			else if(a[i]=='.'){
				if(k==0 && i==0){
					flag=1;
					break;
				}
				k=0;
				cnt++;
				if(cnt>3){
					flag=1;
					break;
				}
			}
			else{
				flag=1;
				break;
			}
		}
		if(!flag && cnt==3)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}