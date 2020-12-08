#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>


using namespace std;
int BSearch(int* R,int n,int v){
	int ans = -1;
	int h=0,t=n-1,i=0;
	while(h<t){
		i = ceil((t+h)/2);
		if(R[i]==v){
			ans = v;
			break;
		}
		else if(R[i]>v){
			t=i-1;
		}
		else{
			h=i+1;
		}
	}
	return ans;
}

int main(){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<BSearch(A,10,3);
	return 0;
}
