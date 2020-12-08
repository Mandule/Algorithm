#include <cstdio>
#include <iostream>
using namespace std;

int A[10000001];
int n;
int ans=0;

void merge_num(int x,int y){
	if(y-x>1){
		int m = x+(y-x)/2;
		int p = x,q = m;
		merge_num(x,m);
		merge_num(m,y);
		while(p<m || q<y){
			if(q>=y || (p<m && A[p]<=A[q])) p++;
			else{
				q++;
				ans += m-p;
			}
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		ans = 0;
		for(int i=0;i<n;i++) cin>>A[i];
		merge_num(0,n);
		cout<<ans<<endl;
	}	
	
	return 0;
} 
