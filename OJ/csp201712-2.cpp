#include <iostream>
#include <queue>
using namespace std;


int main(){
	int n,k;
	while(cin>>n>>k){
		queue<int> Q;
		for(int i=1;i<=n;i++)
			Q.push(i);
		int num = 0;
		while(Q.size()>1){
			num++;
			int id = Q.front();
			Q.pop();
			if(num%k == 0 || num%10 == k) continue;
			Q.push(id);
		}
		int ans = Q.front();
		Q.pop();
		cout<<ans<<endl;
	}
}