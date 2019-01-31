#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


stack<int> S;
int A[100];
int B[100];
int n;

void init(int n){
	while(!S.empty()) 
		S.pop();
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init(n);
		int j=0;
		for(int i=0;i<n;i++){
			S.push(A[i]);
			while(!S.empty()){
				if(B[j] == S.top()){
					S.pop();
					j++;
				}
				else break;
			}
		}
		if(S.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
