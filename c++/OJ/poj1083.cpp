#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;




struct Move{
	int a;
	int b;
	bool operator < (const Move& other) const{
		return b<other.b;
	}
}m[201];

queue<Move> Q;


void init(int n){
	for(int i=0;i<n;i++){
		cin>>m[i].a;
		cin>>m[i].b;
		if(m[i].a%2 == 0) m[i].a -= 1;
		if(m[i].b%2 == 0) m[i].b -= 1;
	}
	sort(m,m+n);
	while(!Q.empty()) Q.pop();
}

int solution(int n){
	if(n==0) return 0;
	Move last = m[0];
	for(int i=1;i<n;i++){
		if(m[i].a>last.b) last = m[i];
		else Q.push(m[i]);
	}
	n=0;
	while(!Q.empty()){
		m[n++] = Q.front();
		Q.pop();
	}
	return 1+solution(n);
}

int main(){
	int T;
	cin>>T;
	while(true){
		int n;
		cin>>n;
		init(n);	
		int ans = solution(n);
		cout<<ans*10<<endl;
	}
	return 0;
}
