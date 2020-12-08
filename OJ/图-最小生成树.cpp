#define LOCAL
#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;


struct edge{
	int a;
	int b;
	int c;
	bool operator <(const edge& other)const{
		return c<other.c;
	}
}E[5000];

set<int> Set;
int N;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	while(cin>>N && N){
		Set.clear();
		int M = N*(N-1)/2;
		for(int i=0;i<M;i++){
			int a,b,c;
			cin>>a>>b>>c;
			E[i].a = a;E[i].b = b;E[i].c = c;
		}
		sort(E,E+M);
		int ans = 0,i=0;
		while(Set.size() != N){
			int a,b,c;
			a=E[i].a;b=E[i].b;c=E[i].c;
			int tmp1 = Set.count(a);
			int tmp2 = Set.count(b);
			if(tmp1 == 0 || tmp2 == 0){
				ans+=c;
				if(tmp1 == 0) Set.insert(a);
				if(tmp2 == 0) Set.insert(b);
			}
			i++;
		}
		cout<<ans<<endl;
	}



	return 0;
}