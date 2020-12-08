#include <cstdio>
#include <iostream>
using namespace std;
bool mark[10001];
int prime[10001];
int size;

void init(){
	size = 0;
	int n=10001;
	for(int i=0;i<n;i++){
		mark[i]=true;
	}
	for(int i=2;i<n;i++){
		if(mark[i]==true){
			for(int j=i*i;j<n;j=j+i){
				mark[j]=false;
			}
			prime[size++]=i;
		}
	}
}

int main(){
	init();
	int x;
	while(scanf("%d",&x)!=EOF){
		int ans_prime[30];
		int ans_size=0;
		int ans_num[30];
		
		for(int i=0;i<size;i++){
			if(x%prime[i]==0){
				int n=1;
				ans_prime[ans_size]=prime[i];
				while(x%prime[i]==0){
					ans_num[ans_size] = n++;
					x /= prime[i];
				}
				ans_size++;
			}
			if(x==1)break;
		}
		cout<<"X"<<x<<endl;
		if(x!=1){
			ans_prime[ans_size]=x;
			ans_num[ans_size++]=1; 
		}
		int ans=0;
		for(int i=0;i<ans_size;i++){
			ans += ans_num[i];
		}
		cout<<ans<<endl;
		for(int i=0;i<ans_size;i++){
			cout<<ans_prime[i]<<"^"<<ans_num[i];
			if(i!=ans_size-1){
				cout<<"*";
			}else{
				cout<<endl;
			}
		}
	}
	return 0;
}
