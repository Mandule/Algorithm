#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long ll;

const int max_word = 1e5;
const int hashSize = 1e5;

string word[max_word];
int m_next[max_word];

int head[hashSize]; 

void initTable(){memset(head,-1,sizeof(head));}

bool try_insert(int wid){
	int num = 0;
	string w = word[wid];
	for(int i=0;i<w.size();i++)
		num = num*2 + w[i]-'a';
	int u = head[num];
	while(u){
		if(word[u] == word[wid]) return false;
		u = m_next[u];
	}
	m_next[wid] = head[num];
	head[num] = wid;
	return true;
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string str;
    while(getline(cin,str) && str!="#"){
    	initTable();
    	int ans = 0;
    	int size = 1 ;
    	stringstream ss(str);
    	while(ss>>str){
    		word[size] = str;
    		if(try_insert(size++)) ans++;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}







