#include <cstdio>
#include <iostream>
using namespace std;


int ans[101][101];
void init(){
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			ans[i][j] = -1;
		}
		ans[i][i] = 0;
	}
}


int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(c < ans[a][b]){
				ans[a][b] = ans[b][a] = c;
				continue;
			}
			ans[a][b] = ans[b][a] = c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(ans[i][k] == -1 || ans[k][j] == -1) continue;
					if(ans[i][j] == -1 || ans[i][k]+ans[k][j] < ans[i][j]){
						ans[i][j] = ans[i][k]+ans[k][j];
					}
				}
			}
		}
		cout<<ans[1][n]<<endl;
	}
	return 0;
}
