#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;
typedef long long ll;


string ex[10000];
int size;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
	while(cin>>n){
		size = 0;
		string str;cin>>str;n--;
		ex[size++] = str+str;
		while(n--){
			cin>>str;
			bool exist = false;
			for(int i=0;i<size;i++)
				if(ex[i].find(str) != string::npos) exist = true;
			if(!exist) ex[size++] = str+str;
		}
		cout<<size<<endl;
	}
    return 0;
}