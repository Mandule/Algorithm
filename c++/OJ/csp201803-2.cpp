#include <iostream>
using namespace std;


int main(){
	int n,L,t;
	cin>>n>>L>>t;
	int ball[n];
	int site[L];
	int dir[n];
	for(int i=0;i<n;i++){
		cin>>ball[i];
		dir[i] = 1;
	}
	while(t--){
		for(int i=0;i<=L;i++)
			site[i] = -1;
		for(int i=0;i<n;i++){
			ball[i] += dir[i];
			if(site[ball[i]] == -1) site[ball[i]] = i;
			else{
				dir[site[ball[i]]] *= -1;
				dir[i] *= -1;
			}
			if(ball[i] == 0 || ball[i] ==L) dir[i] *= -1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ball[i]<<" ";
	}
	cout<<endl;
	return 0;
}