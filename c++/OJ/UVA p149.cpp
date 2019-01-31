#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_D=20;
bool node[1<<20];
int n;

void init(int d){
	n = (1<<d)-1;
	memset(node,false,sizeof(node));
}

int putBall(int nodeNum){
	if(nodeNum*2 > n) return nodeNum;
	if(node[nodeNum]==false){
		node[nodeNum] = !node[nodeNum];
		return putBall(nodeNum*2);	
	}
	else{
		node[nodeNum] = !node[nodeNum];
		return putBall(nodeNum*2+1);
	}
}


int main(){
	int D,I;
	while(scanf("%d%d",&D,&I)!=EOF){
		init(D);
		int ans;
		while(I--){
			ans = putBall(1);
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
