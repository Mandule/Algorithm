#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int max_len;
int n,m;
int edge[100][100];
int dis[100];

int que[120];
int head,rear;

int s,t;


int bfs(){
	head = 0;
	rear = 1;
	int ans;
	while(head<rear){
		int now = que[head];
		head++;
		for(int i=0;i<n;i++)
			if(edge[now][i] ==1 && dis[i]==-1){
				dis[i] = dis[now]+1;
				if(max_len < dis[i]){
					max_len = dis[i];
					ans = i; 
				}
				que[rear++] = i;
			}
	}
	return ans;
}


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	while(cin>>n>>m){
 		memset(edge,-1,sizeof(edge));
 		for(int i=0;i<m;i++){
 			int a,b;
 			cin>>a>>b;
 			edge[a][b] = edge[b][a] = 1;
 		}
 		bool connect = true;
 		memset(dis,-1,sizeof(dis));
 		que[0] = 0;
 		dis[0] = 0;
 		max_len = 0;
 		int s = bfs();
 		for(int i=0;i<n;i++){
 			if(dis[i] == -1){
 				cout<<"No"<<endl;
 				connect = false;
 				break;
 			}
 		}
 		if(connect == false) continue;
  		memset(dis,-1,sizeof(dis));
 		que[0] = s;
 		dis[s] = 0;
 		max_len = 0;
 		int t = bfs();
 		if(max_len>7) cout<<"No"<<endl;
 		else cout<<"Yes"<<endl;
 	}
    return 0;
}