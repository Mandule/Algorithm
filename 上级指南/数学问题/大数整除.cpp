#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

bool mark[10001];
int prime[10001];
int pSize;

int nPrime[10001];
int nIndex[10001];
int nSize;

int aPrime[10001];
int aIndex[10001];
int aSize;

int main(){
	int n,a;
	pSize=0;
	for(int i=0;i<10001;i++){
		mark[i]=true;
	}
	for(int i=2;i<10001;i++){
		if(mark[i]){
			prime[pSize++]=i;
			for(int j=i*i;j<10001;j=j+i){
				mark[j]=false;
			}
		}
	}
	while(scanf("%d %d",&n,&a)!=EOF){
		nSize=0;
		aSize=0;
//		cout<<a<<" = ";
		for(int i=0;i<pSize;i++){
			int tmp = prime[i];
			if(a%tmp == 0){
				aPrime[aSize]=tmp;
				aIndex[aSize]=0;
				while(a%tmp==0){
					aIndex[aSize]++;
					a /= tmp;
				}
				aSize++;
			}
			if(a==1) break;
		}
//		for(int i=0;i<aSize;i++){
//			cout<<aPrime[i]<<"^"<<aIndex[i]<<" ";
//		}
//		cout<<endl;
		
		for(int i=0;i<pSize;i++){
			int tmp = prime[i];
			if(n >= tmp){
				nPrime[nSize]=tmp;
				nIndex[nSize]=0;
			}else{
				break;
			}
			while(n >= tmp){
				nIndex[nSize] += n/tmp;
				tmp = tmp*prime[i]; 
			}
			nSize++;
		}
		
//		cout<<n<<"! = ";
//		for(int i=0;i<nSize;i++){
//			cout<<nPrime[i]<<"^"<<nIndex[i]<<" ";
//		}
//		cout<<endl;
		int k =  INT_MAX;
		int j=0;
 		for(int i=0;i<aSize;i++){
			while(nPrime[j] != aPrime[i] && j<nSize){
				j++;
			}
			if(j==nSize) break;
			int tmp=nIndex[j]/aIndex[i];
			if(k>tmp) k=tmp;
		}
		int ans;
		ans = j==nSize ? 0:k;
		cout<<ans<<endl;
	}
	return 0;
} 









