#include <cstdio>
#include <iostream>
using namespace std;
bool mark[10000];

int main(){
	int n;
	bool has;
	while(scanf("%d",&n)!=EOF){
		has = false;
		for(int i=2;i<n;i++){
			mark[i]=true;
		} 
		for(int i=2;i<n;i++){
			if(mark[i]==true){
				if(i%10==1){
					cout<<i<<" ";
					has = true;
				}
				for(int j=i*i;j<n;j=j+i){
					mark[j]=false;
				}
			}
		}
		if(has==false)cout<<-1;
		cout<<endl;
	}	
	
	return 0;
} 
