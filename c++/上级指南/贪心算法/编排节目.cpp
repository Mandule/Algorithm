#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct program{
	int start;
	int end;
	bool operator < (const program &other)const{
		return end<other.end;
	}
}program[100];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin>>program[i].start>>program[i].end;
		}
		sort(program,program+n);
		int currenTime=0,ans=0;
		for(int i=0;i<n;i++){
			if(currenTime<=program[i].start){
					currenTime = program[i].end;
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
