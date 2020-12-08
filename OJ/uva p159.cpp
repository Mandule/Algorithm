#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 10001;

int sum[MAX_N];

void build(int p){
	int val;
	cin>>val;
	if(val==-1) return;
	sum[p] += val;
	build(p-1);
	build(p+1);
}


bool init(){
	int val;
	cin>>val;
	if(val==-1) return false;
	memset(sum,0,sizeof(sum));
	int pos = MAX_N/2+1;
	sum[pos] = val;
	build(pos-1);
	build(pos+1);
	return true;
}


int main(){
	while(init()){
		int p = 0;
		while(sum[p]==0) p++;
		while(sum[p]!=0){
			cout<<sum[p]<<" ";
			p++;
		}
		cout<<endl;
	}
	return 0;
}
