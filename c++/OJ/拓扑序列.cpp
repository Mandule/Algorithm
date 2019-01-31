#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#define N 100
using namespace std;

vector<int> edge[N];
stack<int> S;
int in[N];

void init(){
	for(int i=0;i<N;i++){
		edge[i].clear();
		in[i] = 0;
	}
	while(!S.empty())
		S.pop();
}


int main(){
	int n,m;	
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		int ans=0;
		init();
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			in[b]++;
		}
		for(int i=0;i<n;i++){
			if(in[i]==0)
				S.push(i);
		}
		while(!S.empty()){
			int tmp = S.top();
			S.pop();
			cout<<tmp<<" ";
			ans++;
			for(int i=0;i<edge[tmp].size();i++){
				in[edge[tmp][i]]--;
				if(in[edge[tmp][i]]==0)
					S.push(edge[tmp][i]);
			}
		}
		if(ans==n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
