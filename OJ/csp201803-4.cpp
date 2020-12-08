#include <iostream>
#include <cmath>
using namespace std;

int maze[3][3];

int spa(){		//返回当前空格数目
	int ans=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(maze[i][j] == 0) ans++;
		}
	}
	return ans;
}

int isWin(int k){	//计算k玩家是否取得胜利，未取得胜利则返回0，取得胜利则返回评估值
	int ans;
	bool win = false;
	for(int i=0;i<3;i++){
		if(maze[i][0]==k && maze[i][1]==k && maze[i][2]==k){
			win = true;
			break;
		}
		else if(maze[0][i]==k && maze[1][i]==k && maze[2][i]==k){
			win = true;
			break;
		}
	}
	if(maze[0][0]==k && maze[1][1]==k && maze[2][2]==k)
		win = true;
	else if(maze[0][2]==k && maze[1][1]==k && maze[2][0]==k)
		win = true;

	if(win == false) return 0;
	ans = spa()+1;
	return ( k== 1) ? ans : -ans;
}

//1号玩家希望评估值越大越好，2号玩家希望评估值越小越好。
//所以1号玩家在选择下子时，总是选择能使最终棋盘评估值最大的位置落子
//2号玩家总是选择能使最终棋盘评估最小的位置落子。

int dfs(int t){	//dfs函数返回当前残局情况下，t玩家能获得的最优棋盘评估值。
	if(spa() == 0) return 0;	//如果平局则返回0
	int Max = -10;		//Max评估值 只有在t =1 时有意义。
	int Min = 10;		//Min评估值 只有在t =2 时有意义。
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(maze[i][j] == 0){
				//遍历当前玩家t所有可以下的空格
				maze[i][j] = t;
				int value = isWin(t);	//计算下完这一步后t玩家是否获得胜利，并获得棋盘评估值。
				if(value != 0 ){		//如果t玩家获得胜利。
					maze[i][j] = 0;	//回溯
					//dfs函数出口。
					return t==1 ? max(Max,value) : min(Min,value);	//返回相对该玩家的最优评估
				}
				//如果下完这步t玩家没有获得胜利
				if(t == 1) Max = max(Max,dfs(2));
				else Min = min(Min,dfs(1));
				maze[i][j] = 0;		//回溯
			}
		}
	}
	//dfs函数出口。
	return t == 1 ? Max : Min;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>maze[i][j];
			}
		}
		int a = isWin(1);
		int b = isWin(2);
		if(a != 0){
			cout<<a<<endl;
			continue;
		}
		if(b != 0){
			cout<<b<<endl;
			continue;
		}
		int ans = dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}