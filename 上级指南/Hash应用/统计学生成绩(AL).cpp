#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int score[1000];
	int n;
	int v;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&score[i]);
		}
		scanf("%d",&v);
		printf("%d\n",count(score,score+n,v));//或者使用Hash数组记录每个成绩的学生个数。 
	}
	return 0;
}
