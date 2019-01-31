#include <cstdio>
#include <iostream>
using namespace std;

char shape[80][80];
char center,edge;

void Fill(int Sx,int Sy,int size,char c){
	if(size==-1) return;
	for(int i=Sx;i<Sx+size;i++){
		shape[i][Sy] = c;
		shape[i][Sy+size-1] = c;
	}
	for(int i=Sy;i<Sy+size;i++){
		shape[Sx][i] = c;
		shape[Sx+size-1][i] = c;
	}
	c = c==center? edge:center;
	Fill(Sx+1,Sy+1,size-2,c);
}

int main(){
	int n;	
	while(scanf("%d %c %c",&n,&center,&edge)!=EOF){
		Fill(0,0,n,edge);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c",shape[i][j]);
			}
			printf("\n");
		}
	}
	
} 
