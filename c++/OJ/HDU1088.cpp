#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    string artical;
    string word;
    while(getline(cin,word)) artical += word+" ";
    stringstream ss(artical);
    bool first = true;
    int n=0;
    while(ss>>word){
    	if(word == "<br>"){
    		n=0;
    		cout<<endl;
    	}
    	else if(word == "<hr>"){
    		if(n!=0) cout<<endl;
    		for(int i=0;i<80;i++) cout<<'-';
    		cout<<endl;
    		n=0;
    	}
		else{
    		if(n+word.size()>80) {
    			cout<<endl<<word;
    			n = word.size();
    		}
    		else{
    			if(n==0) cout<<word;
    			else cout<<" "<<word;
    			n++;
    			n += word.size();
    		}
    	}
    }
    cout<<endl;
    return 0;
}