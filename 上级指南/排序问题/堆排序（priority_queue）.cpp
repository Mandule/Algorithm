#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int> Q;

int main(){
	int n; 
	int tmp;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			Q.push(tmp);
		}
		while(!Q.empty()){
			printf("%d ",Q.top());
			Q.pop();
		}
		printf("\n");
	}
		
	return 0;
} 
