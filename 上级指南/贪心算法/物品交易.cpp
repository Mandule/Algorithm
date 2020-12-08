#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct goods{
	double j;
	double f;
	double s;
	bool operator < (const goods &othergood)const{
		return s>othergood.s;
	}
}goods[1000];

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==-1 && n==-1) break;
		for(int i=0;i<n;i++){
			cin>>goods[i].j>>goods[i].f;
			goods[i].s=goods[i].j/goods[i].f;		
		}
		sort(goods,goods+n);
		int index=0;
		double ans=0;
		while(m>0 && index<n){
			if(m>=goods[index].f){
				ans+=goods[index].j;
				m-=goods[index].f;
			}
			else{
				ans+=goods[index].s*m;
				m=0;
			}
			index++;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
