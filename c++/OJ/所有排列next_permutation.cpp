#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int p[10001]; 

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			cin>>p[i]5;
		sort(p,p+n);
		do{
			for(int i=0;i<n;i++)
				cout<<p[i]<<" ";
			cout<<endl;
		}while(next_permutation(p,p+n));
	}
	return 0;
}
