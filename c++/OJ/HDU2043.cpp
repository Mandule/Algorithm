#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const char sp[7]={'~','!','@','#','$','%','^'};
set<char> Set[4];


int which(char c){
	for(int i=0;i<4;i++)
		if(Set[i].count(c)) return i;
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	for(char i='A';i<='Z';i++) Set[0].insert(i);
	for(char i='a';i<='z';i++) Set[1].insert(i);
	for(char i='0';i<='9';i++) Set[2].insert(i);
	for(int i=0;i<7;i++) Set[3].insert(sp[i]);
    int n;
    cin>>n;
    getchar();
    while(n--){
    	string pw;
    	int a[4];
    	memset(a,0,sizeof(a));
    	getline(cin,pw);
    	for(int i=0;i<pw.size();i++){
    		int tmp = which(pw[i]);
    		a[tmp]++;
    	}
    	int n=0;
    	for(int i=0;i<4;i++) if(a[i]==0) n++;
    	cout<<(n>1?"NO":"YES")<<endl;
    }
    return 0;
}