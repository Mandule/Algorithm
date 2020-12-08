#include <cstdio>
#include <iostream>
using namespace std;

int City[1001];
int n,m;

void init(){
	for(int i=1;i<=n;i++){
		City[i]=-1;
	}
}

int findRoot(int x){
	if(City[x] == -1)	return x;
	int tmp = findRoot(City[x]);
	City[x] = tmp;
	return tmp;	
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		cin>>m;
		init();
		int c1,c2,ans=0;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>c1>>c2;
			a = findRoot(c1);
			b = findRoot(c2);
			if(a != b) City[b] = a;
		}
		for(int i=1;i<=n;i++){
			if(City[i]== -1) ans++;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
