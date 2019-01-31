#include <stdio.h>
#include <iostream>
using namespace std;

void Bubble(int* R,int n){
	int end = n-1;
	int tmp = 0;
	while(end>0){
		int t = 0;
		for(int i=0;i<end;i++){
			if(R[i]>R[i+1]){
				tmp = R[i+1];
				R[i+1] = R[i];
				R[i] = tmp;
				t = i+1;	
			}
		}
		end = t;
	}
}
int main(){
	return 0;
}
