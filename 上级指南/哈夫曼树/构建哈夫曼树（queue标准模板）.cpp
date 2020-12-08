#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue< int,vector<int>,greater<int> > Q;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans = 0;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			Q.push(tmp);
		}
		while(Q.size()>1){
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a+b;
			Q.push(a+b);
		}
		Q.pop();
		cout<<ans<<endl;
	}
	return 0;
}
