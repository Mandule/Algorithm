#include <cstdio>
#include <iostream>
#include <queue> 
#include <vector>
using namespace std;

queue<int> Q;
vector<int> edge[501];
int inDegree[501];

void init(){
	while(!Q.empty()){
			Q.pop();
	} 
	for(int i=0;i<501;i++){
		edge[i].clear();
		inDegree[i] = 0;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			inDegree[b]++;
		}
		for(int i=0;i<n;i++){
			if(inDegree[i]==0) Q.push(i);
		}
		while(!Q.empty()){
			n--;
			int x = Q.front();
			Q.pop();
			for(int i=0;i<edge[x].size();i++){
				int t = edge[x][i];
				inDegree[t]--;
				if(inDegree[t]==0){
					Q.push(t);
				} 
			}
		}
		cout<< (n==0?"YES":"NO")<<endl; 
	}
	return 0;
}
