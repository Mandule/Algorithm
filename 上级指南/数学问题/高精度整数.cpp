#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct bigInt{
	int digit[1000];
	int size;
	void init(){
		size = 0;
		for(int i=0;i<1000;i++){
			digit[i]=0;
		}
	}
	bigInt operator + (const bigInt& other) const {
		bigInt ans;
		ans.init();
		bool carry = false;
		int idx = 0;
		while(idx<size || idx<other.size){
			int tmp = digit[idx]+other.digit[idx];
			tmp = carry ? tmp+1 : tmp ;
			carry = tmp<10 ? false : true;
			tmp = tmp<10 ? tmp : tmp-10;
			ans.digit[ans.size++] = tmp;
			idx++;
		}
		if(carry)	ans.digit[ans.size++]=1;
		int start =0,end= ans.size-1;
		while(start<end){
			int tmp = ans.digit[end];
			ans.digit[end] = ans.digit[start];
			ans.digit[start] = tmp;
			start++;
			end--;
		}
		return ans;
	}
};
bigInt a,b,ans;
char astr[1000];
char bstr[1000];

int main(){
	while(scanf("%s %s",&astr,&bstr)!=EOF){
		int len1=strlen(astr),len2=strlen(bstr);
		a.init();b.init();ans.init();
		
		for(int i=len1-1;i>=0;i--){
			a.digit[a.size++] = astr[i]-'0';
		}
		for(int i=len2-1;i>=0;i--){
			b.digit[b.size++] = bstr[i]-'0';
		}
		
		ans = a+b;
		for(int i=0;i<ans.size;i++){
			cout<<ans.digit[i]; 
		}
		cout<<endl;
	}
	return 0;
} 
