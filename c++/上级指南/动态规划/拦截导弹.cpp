#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int F[25];
int high[25];

int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		for(int i=0;i<k;i++){
			cin>>high[i];
		}
		int ans;
		for(int i=0;i<k;i++){
			F[i]=1;
			for(int j=0;j<i;j++){
				if(high[i]<=high[j]){
					F[i] = max(F[i],F[j]+1);
				}
			}
			ans = max(ans,F[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
