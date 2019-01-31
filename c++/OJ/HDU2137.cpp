#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long ll;

char map[80][80];
int len;
int row;

void init(){
	for(int i=0;i<80;i++)
		for(int j=0;j<80;j++)
			map[i][j]=' ';
}

void turnTo(int i){
	int tmp = row*2;
	if(i == 1)for(int i=0;i<len;i++)
		swap(map[row][i],map[tmp-i][i]);
	if(i == 2)for(int i=0;i<len;i++)
		swap(map[row][i],map[tmp-i][row]);
	if(i == 3)for(int i=0;i<len;i++)
		swap(map[row][i],map[tmp-i][tmp-i]);
	if(i == 4)for(int i=0;i<row;i++)
		swap(map[row][i],map[row][tmp-i]);
	if(i == 5)for(int i=0;i<len;i++)
		swap(map[row][i],map[i][tmp-i]);
	if(i == 6)for(int i=0;i<len;i++)
		swap(map[row][i],map[i][row]);
	if(i == 7)for(int i=0;i<len;i++)
		swap(map[row][i],map[i][i]);
}

void show(){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
}

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string str;
    int n;
    while(cin>>str>>n){
    	init();
    	len = str.size();
    	row = len/2;
    	memcpy(map[row],str.c_str(),sizeof(map[row]));
    	n = n%8;
    	turnTo(n);
    	show();
    } 
    return 0;
}