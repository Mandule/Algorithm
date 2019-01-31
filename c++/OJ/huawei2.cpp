#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;

int mark[25];

struct task{
	int start;
	int end;
	int time;
	bool operator < (const task& other) const{
		if(time < other.time) return true;
		else if( time == other.time){
			return start > other.start;
		}
		else return false;
	}
};

struct ans_task{
	int start;
	int end;
	bool operator < (const task& other) const{
		return end > other.end;
	}	
};

priority_queue<task> PQ;
priority_queue<ans_task> ans_PQ;



int main(){
	string str;
	while(cin>>str && str != "0"){
		for(int i=9;i<=21;i++) mark[i] = 0;
		do{
			for(int i=0;i<str.size();i++)if(str[i] == ',') str[i] = ' ';
			stringstream ss(str);
			task tmp;
			ss>>tmp.start>>tmp.end;
			tmp.time = tmp.end-tmp.start;
			PQ.push(tmp);
		}while(cin>>str && str!= "0,0");
		while(!PQ.empty()){
			task now = PQ.top();PQ.pop();
			bool can = true;
			for(int i=now.start;i<now.end;i++){
				if(mark[i] == 1){
					can = false;
					break;
				}
			}
			if(can){
				for(int i=now.start;i<now.end;i++)
					mark[i] = 1;
				ans_task tmp;
				tmp.start = now.start;
				tmp.end = now.end;
				ans_PQ.push(tmp);
			}
		}
		while(!ans_PQ.empty()){
			ans_task now = ans_PQ.top();
			ans_PQ.pop();
			cout<<now.start<<","<<now.end<<endl;
		}
	}
	return 0;
}