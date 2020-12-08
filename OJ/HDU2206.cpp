#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string str;
    while(getline(cin,str)){
    	int i=0,j=0;
    	int n=0;
    	bool ans = true;
    	string substr[4];
    	while(1){
    		j = str.find('.',i);
    		if(j == -1) break;
			substr[n++] = str.substr(i,j-i);
			i = j+1;    		
    	}
    	if( n!=3 ) ans =false;
    	if(!ans) {cout<<"NO"<<endl;continue;}//判断是否正好三个“.” 
    	
    	substr[3] = str.substr(i);
    	str.clear();
    	for(int i=0;i<4;i++){
    		if(substr[i]==""){ans=false;break;}//判断是否有空串
    		//判断是否有其他字符
    		if(substr[i].find_first_not_of("0123456789")!=string::npos){ans=false;break;}
    		str += substr[i]+"  ";
    	}
    	if(!ans){cout<<"NO"<<endl;continue;}
    	stringstream ss(str);
    	for(int i=0;i<4;i++){
    		int tmp;
    		ss>>tmp;
    		if(tmp<0 || tmp>255){ans=false;break;}
    	}
    	cout<<(ans ? "YES" : "NO")<<endl;
    }
    return 0;
}