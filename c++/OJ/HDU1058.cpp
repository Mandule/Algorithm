#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

priority_queue< ll , vector<ll> , greater<ll> > pq;
set<ll> s;

ll find(int rank){
	int n = 0;
	pq.push(1);
	s.insert(1);

	while(!pq.empty()){
		
		ll now = pq.top();
		pq.pop();
		if(++n == rank) return now;

		ll next[4];
		next[0] = now*2;
		next[1] = now*3;
		next[2] = now*5;
		next[3] = now*7;
		for(int i=0;i<4;i++)if( next[i]>0 && !s.count(next[i])){
			pq.push(next[i]);
			s.insert(next[i]);
		}
	}
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    	while(!pq.empty()) pq.pop();
    	s.clear();
    	cout<<find(n)<<endl;
    }
    return 0;
}