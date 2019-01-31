#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef int state[9];
const int maxstate = 1000000;
const int hashsize = 1000003;
const state goal={1,2,3,4,5,6,7,8,0};

state st[maxstate];//数组模拟队列

int p[maxstate];//保存路径
int op[maxstate];//保存每一步的操作
int head[hashsize];//hash表头
int my_next[maxstate];//hash链表

int go[4][2]={
	-1,0,
	1,0,
	0,-1,
	0,1	
};

void init(){
	memset(head,0,sizeof(head));
}

int my_hash(state s){
	int v = 0;
	for(int i=0;i<9;i++) v=v*10 +s[i];
	return v%hashsize;
}

bool try_insert(int s){
	int h = my_hash(st[s]);
	int u = head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0) return false;
		u = my_next[u];
	}
	my_next[s] = head[h];
	head[h] = s;
	return true;
}

int  BFS(){
	init();
	int front = 1;
	int rear = 2;
	while(front<rear){
		state& now = st[front];
		if(memcmp(goal,now,sizeof(now)) == 0) return front;

		int z=0;
		while(now[z] != 0) z++;
		int x = z/3,y=z%3;

		for(int i=0;i<4;i++){
			int nx = x+go[i][0];
			int ny = y+go[i][1];

			int nz = nx*3+ny;
			if(nx<0 || nx>2 || ny<0 || ny> 2) continue;

			state& t = st[rear];
			memcpy(t,now,sizeof(now));
			swap(t[z],t[nz]);
			p[rear] = front;
			op[rear] = i;
			
			if(try_insert(rear)) rear++;
		}
		front++;
	}
	return false;
}


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string str;
	while(getline(cin,str)){
		for(int i=0;i<str.size();i++){
			if(str[i] == ' ') str.erase(i,2);
			if(str[i] == 'x') str[i] = '0';
			st[1][i] = str[i]-'0';
		}
		int ans = BFS();
		string s="";
		if(ans>0){
			while(p[ans]!=0){
				string c;
				switch(op[ans]){
					case 0 : c = "u";break;
					case 1 : c = "d";break;
					case 2 : c = "l";break;
					case 3 : c = "r";break;
				}
				s = s+c;
				ans = p[ans];
			}
			for(int i=s.size()-1;i>=0;i--) cout<<s[i];
			cout<<endl;
		}
		else cout<<"unsolvable"<<endl;
	}
    return 0;
}