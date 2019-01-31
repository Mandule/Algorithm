#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n);
	int min = INT_MAX;
	for(int i=1;i<n;i++){
		if(min > (num[i]-num[i-1]))
			min = num[i]-num[i-1];
	}
	cout<<min<<endl;
	return 0;
}