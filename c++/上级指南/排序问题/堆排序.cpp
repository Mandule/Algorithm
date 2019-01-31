#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int A[10] = {26,5,77,1,61,11,59,15,48,19};
	make_heap(A,A+10);
	sort_heap(A,A+10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<"  ";
	} 
	return 0;
}
