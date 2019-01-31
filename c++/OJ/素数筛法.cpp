#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int mark[10001];
int num[10001];
int size=0;


int main(){
	int n;
	for(int i=2;i<10001;i++)
		mark[i]=1;
	for(int i=2;i*i<10001;i++){
		if(mark[i]==1){
			num[size++]=i;
			for(int j=i*i;j<10001;j=j+i)
				mark[j]=0;
		}
	}
	while(scanf("%d",&n)!=EOF){		
		for(int i=0;i<size;i++){
			if(num[i]<n && num[i]%10==1)
				cout<<num[i]<<' '; 
		}		
		cout<<endl;
	}
	return 0;
}
