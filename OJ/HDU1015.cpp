#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;
int target;
string str;
string ans;
string tmp;
int vis[20];

bool isOk(string s){
	int n=0;
	int k=1;
	for(int i=0;i<s.size();i++){
		n += pow(s[i]-'A'+1,i+1)*k;
		k *= -1;
	}
	if( n == target) return true;
	else return false;
}

void dfs(int k){
	if(k == 5){
		if(isOk(tmp) && tmp > ans) ans = tmp;
		return;
	}
	for(int i=0;i<str.size();i++){
		if(vis[i] == 1) continue;
		vis[i] = 1;
		tmp.insert(tmp.end(),str[i]);
		dfs(k+1);
		tmp.erase(tmp.end()-1);
		vis[i] = -1;
	}
}

void init(){
	ans.clear();
	tmp.clear();
	memset(vis,-1,sizeof(vis));
}

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	while(cin>>target>>str){
 		if( target==0 && str=="END") break;
 		init();
 		dfs(0);
 		if(ans.size()==0) cout<<"no solution"<<endl;
 		else cout<<ans<<endl;
 	}
 	return 0;
}