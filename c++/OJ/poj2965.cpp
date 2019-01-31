#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

int map[4][4];
int x[50];
int y[50];
int ansx[50];
int ansy[50];
int ans = INT_MAX;

void initMap(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			char tmp;
			cin>>tmp;
			if(tmp=='-') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
}

bool isOK(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(map[i][j]==0) return false;
	return true;
}


void turn(int x,int y){
	if(x>=0 && x<=3 && y>=0 && y<=3)
		map[x][y] = !map[x][y];
}

void flip(int s){
	int x = s/4;
	int y = s%4;
	for(int i=0;i<4;i++){
		turn(x,i);
		turn(i,y);
	}
	turn(x,y);
}

void DFS(int s,int n){
	if(isOK()){
		if(n<ans){
			ans = n;
			for(int i=0;i<n;i++){
				ansx[i] = x[i];
				ansy[i] = y[i];
			}	
		}
		return;
	}
	if(s>=16) return;
	DFS(s+1,n);
	flip(s);
	x[n] = s/4+1;
	y[n] = s%4+1;
	DFS(s+1,n+1);
	flip(s);
}



int main(){
	initMap();
	DFS(0,0);
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
		cout<<ansx[i]<<" "<<ansy[i]<<endl;
	return 0;
}
