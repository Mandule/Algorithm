#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main(){
	char str1[101];
	int num1[26];
	char str2[101];
	int num2[26];
	while(scanf("%s%s",str1,str2)!=EOF){
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		if(len1 != len2) {
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<26;i++) num1[i]=num2[i]=0;
		for(int i=0;i<len1;i++){
			num1[str1[i]-'A']++;
			num2[str2[i]-'A']++;
		}
		sort(num1,num1+26);
		sort(num2,num2+26);
		bool ans=true;
		for(int i=0;i<26;i++){
			if(num1[i]!=num2[i]){
				ans=false;
				break;
			}
		}
		cout<<(ans?"YES":"NO")<<endl;
	}
	
	return 0;
} 
