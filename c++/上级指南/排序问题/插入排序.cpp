#include <stdio.h>
#include <iostream>
using namespace std;
void insertSort(int* A,int n){
	for(int j=2;j<n;j++){
		int i = j-1;
		int k = A[j];
		while(i>-1 && k<A[i]){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = k;
	}
	
}
int main(){
	int A[5]={4,5,1,3,2};
	insertSort(A,5);
	return 0;
} 
