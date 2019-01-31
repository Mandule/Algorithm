#include <cstdio>
#include <iostream>
using namespace std;

int prime[10001]; 
bool mark[10001];
int size;

void primeInit(){
	size=0;
	for(int i=0;i<10001;i++) mark[i]=true;
	mark[0] = mark[1] = false;
	for(int i=2;i*i<10001;i++){
		if(mark[i]){
			prime[size++] = i;
			for(int j=i*i;j<10001;j=j+i) mark[j] = false;
		}
	}
}


int solution(int num){
	int ans = 0;
	for(int i=0;i<size;i++){
		int sum=0;
		for(int j=i;j<size;j++){
			sum += prime[j];
			if(sum<num) continue;
			if(sum == num)ans++;
			break;
		}
	}
	return ans;
}

int main(){
	int num;
	primeInit();
	while(scanf("%d",&num)!=EOF){
		if(num==0) break;
		cout<<solution(num)<<endl;
	}
	return 0;
}
