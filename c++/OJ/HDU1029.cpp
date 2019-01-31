#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;


map<int,int> Map;


bool cmp(const pair<int,int> p1,const pair<int,int> p2){
	return p1.second<p2.second;
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		Map.clear();
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			if(!Map.count(tmp)) Map[tmp] = 1;
			else Map[tmp]++;
		}
		map<int,int>::iterator it = max_element(Map.begin(),Map.end(),cmp);
		cout<<it->first<<endl;
	}    
    return 0;
}