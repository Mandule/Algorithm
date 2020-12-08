#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

priority_queue< int,vector<int>,greater<int> > Q; 

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			Q.push(tmp);
		}
		int ans=0;
		while(Q.size()>1){
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			int c = a+b;
			Q.push(c);
			ans = ans+c;
		}
		Q.pop();
		cout<<ans<<endl;
	}
	return 0;
}
