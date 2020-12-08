#define LOCAL
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N,M;

int node[1005];


int findRoot(int i){
	if(node[i] == -1) return i;
	int root = findRoot(node[i]);
	node[i] = root;
	return root;
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	while(cin>>N){
		if(N==0) break;
		cin>>M;
		memset(node,-1,sizeof(node));
		for(int i=0;i<M;i++){
			int a,b;
			cin>>a>>b;
			a = findRoot(a);
			b = findRoot(b);
			if( a!= b) node[b] = a;
		}
		int ans = 0;
		for(int i=1;i<=N;i++)
			if(node[i] == -1) ans++;
		cout<<ans-1<<endl;
	}
	return 0;
}