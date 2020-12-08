#include <cstdio>
#include <cmath>
#include <iostream>
#include <climits>
using namespace std;

int mark[1001];
int num[1001];
int size;

int a_num[101];
int a_e[101];
int a_size;

int n_num[30];
int n_e[30];
int n_size;

void init(){
	size=0;
	for(int i=2;i<1001;i++)
		mark[i] = 1;
	for(int i=2;i*i<1001;i++)
		if(mark[i]==1){
			num[size++]=i;
			for(int j=i*i;j<1001;j=j+i)
				mark[j]=0;
		}
}

void A(int a){
	a_size = 0;
	for(int i=0;i<size;i++){
		int tmp = num[i];
		if(a==1) break;
		if(a%tmp==0){
			a_num[a_size] = tmp;
			a_e[a_size] = 0;
			while(a%tmp==0){
				a_e[a_size]++;
				a = a/tmp;
			}
			a_size++;
		}
	}
}

void N(int n){
	n_size=0;
	for(int i=0;i<size;i++){
		int tmp = num[i];
		if(tmp>n) break;
		n_num[n_size] = tmp;
		n_e[n_size] = 0;
		int t=tmp;
		while(t <= n)	{
			n_e[n_size] += n/t;
			t *= tmp;
		}
		n_size++;
	}
}


int solution(){
	int k=INT_MAX;
	if(n_size<a_size) return -1;
	int j=0;
	int n=0;
	for(int i=0;i<a_size;i++){
		while(j<n_size && n_num[j]!=a_num[i]) j++;
		n++;
		k = min(k,n_e[j]/a_e[i]);
	}
	if(n!=a_size) return -1; 
	return k;
}

int main(){
	int n,a;
	init();
	while(scanf("%d%d",&n,&a)!=EOF){
		A(a);
		N(n);
		cout<<solution()<<endl;
	}
	
	return 0;
}
