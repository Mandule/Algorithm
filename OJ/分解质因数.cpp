#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int mark[10001];
int num[10001];
int size;

int ans[10001];
int e[10001];
int ans_size;


void init(){
	size=0;
	for(int i=2;i<10001;i++)
		mark[i] = 1;
	for(int i=2;i<10001;i++)
		if(mark[i] ==1 ){
			num[size++] = i;
			for(int j=i*i;j<10001;j+=i)
				mark[j] = 0;
		}
}
int solution(int n){
	ans_size = 0;
	int solution_ans=0;
	for(int i=0;i<size;i++){
		int tmp = num[i];
		if(n==1) break;
		if(n%tmp==0){
			ans[ans_size] = tmp;
			e[ans_size] = 0;
			while(n%tmp==0){
				e[ans_size]++;
				n = n/tmp;
			}
			solution_ans = solution_ans+e[ans_size];
			ans_size++;
		}
	}
	if(n!=1){
		ans[ans_size]=n;
		e[ans_size]=1;
		ans_size++;
	}
	return solution_ans;
}




int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		cout<<solution(n)<<endl;
	}
	
	return 0;
}
