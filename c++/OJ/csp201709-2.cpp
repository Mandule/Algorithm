#include <iostream>
#include <queue>
using namespace std;

struct task{
	int state;
	int key_id;
	int time;
	bool operator <(const task& other) const{
		if(time > other.time)
			return true;
		else if(time == other.time && state == 1)
			return true;
		else 
			return false;
	}
};

int site[1005];
priority_queue<task> PQ;

int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i=1;i<=n;i++)
			site[i] = i;
		for(int i=0;i<k;i++){
			int w,s,c;
			cin>>w>>s>>c;
			task tmp;

			tmp.state = 0;
			tmp.key_id = w;
			tmp.time = s;
			PQ.push(tmp);

			tmp.state = 1;
			tmp.time = s+c;
			PQ.push(tmp);
		}
		while(!PQ.empty()){
			task now = PQ.top();PQ.pop();
			if(now.state == 0){	//拿钥匙
				for(int i=1;i<=n;i++){
					if(site[i] == now.key_id){
						site[i] = 0;
						break;
					}
				}
			}
			if(now.state == 1){	//还钥匙
				for(int i=1;i<=n;i++){
					if(site[i] == 0){
						site[i] = now.key_id;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<site[i]<<" ";
		}
		cout<<endl;	
	}
	return 0;
}