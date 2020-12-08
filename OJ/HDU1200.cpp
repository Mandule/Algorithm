#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    int n;
    char m[25][25];
    while(cin>>n){
    	if(n==0) break;
    	getchar();
    	string str;
    	getline(cin,str);
    	stringstream ss(str);
    	char ch;
    	int row=0;
    	int col=0;
    	bool pos = true;
    	while(ss>>ch){
    		m[row][col] = ch;
    		if(pos){
    			col++;
    			if(col == n){
    				col--;
    				row++;
    				pos = false;
    			}
    		}
    		else{
    			col--;
    			if(col == -1){
    				col++;
    				row++;
    				pos = true;
    			}
    		}
    	}
    	for(int i=0;i<n;i++)
    		for(int j=0;j<row;j++)
    			cout<<m[j][i];
    	cout<<endl;
    }
    return 0;
}