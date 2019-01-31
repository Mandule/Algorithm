#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int num[100];
int F[100];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		for(int i=0;i<n;i++){
			F[i]=1;
			for(int j=0;j<i;j++){
				if(num[i]>num[j]){
					F[i] = max(F[i],F[j]+1);	
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<F[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
