#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int num[1000001];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    	for(int i=0;i<n;i++)
    		scanf("%d",&num[i]);
    	sort(num,num+n);
    	int ans = (n+1)/2;
    	cout<<num[ans]<<endl;
    }
    return 0;
}