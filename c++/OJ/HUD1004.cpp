#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string,int> cnt;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		cnt.clear();
		string color; 
		for(int i=0;i<n;i++){
			cin>>color;
			if(!cnt.count(color)) cnt[color] = 1;
			else cnt[color]++;
		}
		map<string,int>::iterator it;
		int max = 0;
		for(map<string,int>::iterator i = cnt.begin();i!=cnt.end();i++){
			if(i->second > max){
				it = i;
				max = i->second;
			}
		}
		cout<<it->first<<endl;
	}

	return 0;
}
