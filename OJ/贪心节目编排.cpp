#include <cstdio>
#include <algorithm>

using namespace std;

struct play{
	int start;
	int end;
	bool operator < (const play& other)const{
		return end<other.end; 
	}
}p[100];

int main (){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].start,&p[i].end);
		}
		sort(p,p+n);
		play tmp = p[0];
		ans++;
		for(int i=1;i<n;i++){
			if(p[i].start >= tmp.end){
				ans++;
				tmp = p[i];
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
