#include <cstdio>
#include <iostream>
#include <cstring> 
#include <sstream>
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
	void init(int n){
		init();
		stringstream stream;
		char str[1000];
		stream<<n;
		stream>>str;
		int len = strlen(str);
		for(int i=len-1;i>-1;i--){
			digit[size++] = str[i]-'0';
		}
		
	}
	void init(char str[]){
		init();
		int len = strlen(str);
		for(int i=len-1;i>-1;i--){
			digit[size++] = str[i]-'0';	
		}
	}
	
	friend ostream& operator <<(ostream &output,const bigInt &ans){
		for(int i=ans.size-1;i>-1;i--){
			output<<ans.digit[i];
		}
		return output;
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
		return ans;
	}
	
	bigInt operator * (const int a) const{
		bigInt ans;
		ans.init();
		int carry = 0;
		int idx = 0;
		while(idx<size){
			int tmp = digit[idx++]*a;
			tmp = carry==0 ? tmp : tmp+carry;
			carry = tmp<10 ? 0 : tmp/10;
			tmp = tmp<10 ? tmp : tmp%10;
			ans.digit[ans.size++] = tmp;
		}
		if(carry !=0) ans.digit[ans.size++] = carry;
		return ans;
	}
	
	bigInt operator * (const bigInt &other) const{
		bigInt ans;
		bigInt tmp;
		ans.init(0);
		for(int i=0;i<other.size;i++){
			tmp.init();
			tmp = *this * other.digit[i];
			for(int j=0;j<i;j++){
				tmp = tmp*10;
			}
			ans = ans+tmp;
		}
		return ans;
		
	}
};

bigInt tmp,ans;

int main(){
	int n;
	
	while(scanf("%d",&n)!=EOF){
		ans.init(1);
		for(int i=1;i<=n;i++){
			ans = ans*i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
