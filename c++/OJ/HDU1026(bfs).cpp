#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

struct state{
    int x,y,t,
    int px,py;
    bool operator < (const state& other)const{return t>other.t;}
}node[111][111];

priority_queue<state> PQ;
stack<state> path;
char maze[100][100];
int vis[111][111];
int dx,dy;
int n,m;
int min_t;
bool exist;


int go[][2]={
    -1,0,
    1,0,
    0,1,
    0,-1
};

void init(){
    memset(vis,-1,sizeof(vis));
    while(!PQ.empty()) PQ.pop();
    while(!path.empty()) path.pop();
    dx=n-1;dy=m-1;
    exist = false;
}


int bfs(){
    while(!PQ.empty()){
        state now = PQ.top();PQ.pop();
        if(now.x == dx && now.y == dy){
            min_t = now.t;
            return 1;
        }
        for(int i=0;i<4;i++){
            int nx = now.x+go[i][0];
            int ny = now.y+go[i][1];
            int nt = now.t+1;

            if(nx <0 || nx>n-1 || ny<0 || ny>m-1) continue;
            if(maze[nx][ny] == 'X') continue;
            if(vis[nx][ny] == 1) continue;
           
            if(maze[nx][ny]<='9' && maze[nx][ny]>='0')
                nt += maze[nx][ny]-'0';

            vis[nx][ny] = 1;
            state& next = node[nx][ny];
            next.px = now.x;
            next.py = now.y;
            next.x = nx;
            next.y = ny;
            next.t = nt;
            PQ.push(next);
        }
    }
    return 0;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m){
        init();
    	for(int i=0;i<n;i++)
    		cin>>maze[i];
        state& start = node[0][0];
        start.x = 0;
        start.y = 0;
        start.t = 0;
        start.px = -1;
        start.py = -1;
        vis[0][0] = 1;

        PQ.push(start);
        int ans = bfs();
        if(ans == 0){
            cout<<"God please help our poor hero."<<endl<<"FINISH"<<endl;
            continue;
        }
        cout<<"It takes "<<min_t<<" seconds to reach the target position, let me show you the way."<<endl;
        state now = node[dx][dy];
        while(now.px!= -1 && now.py!=-1){
            path.push(now);
            now = node[now.px][now.py];
        }

        now = node[0][0];
        int time = 1;
        while(!path.empty()){
            state next = path.top();path.pop();
            printf("%ds:(%d,%d)->(%d,%d)\n",time++,now.x,now.y,next.x,next.y);
            if(maze[next.x][next.y]<='9' && maze[next.x][next.y]>='0'){
                int tmp = maze[next.x][next.y]-'0';
                while(tmp--)
                    printf("%ds:FIGHT AT (%d,%d)\n",time++,next.x,next.y);
            }
            now = next;
        }
        cout<<"FINISH"<<endl;
    }
    return 0;
}