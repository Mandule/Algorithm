#include <cstdio>

const int MAX_N = 100005;

int box[MAX_N];
int left[MAX_N];
int right[MAX_N];
bool isRight;
int n;

void link(int a,int b){
	right[a] = b;
	left[b] = a;
}

void action1(int x,int y){
	link(left[x],right[x]);
	link(left[y],x);
	link(x,y);
}
void action2(int x,int y){
	link(left[x],right[x]);
	link(x,right[y]);
	link(y,x);
}
void action3(int x,int y){
	int x_left = left[x];
	int x_right = right[x];
	int y_left = left[y];
	int y_right = right[y];
	link(x_left,y);
	link(y,x_right);
	link(y_left,x);
	link(x,y_right);
}

int init(int n){
	isRight = true;
	box[0] = 0;
	for(int i=1;i<=n;i++){
		box[i] = i;
		link(i-1,i);
	}
	link(n,0);
}


int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init(n);
		while(m--){
			int type,x,y;
			scanf("%d",&type);
			if(type!=4)
				scanf("%d%d",&x,&y);
			switch(type){
				case 1 : {
					if(isRight)
						action1(x,y);
					else
						action2(x,y);
					break;
				}
				case 2 : {
					if(isRight)
						action2(x,y);
					else
						action1(x,y);
					break;
				}
				case 3 : action3(x,y);break;
				case 4 : isRight = !isRight;break; 
			}
		}
		long long ans = 0;
		if(isRight)
			for(int i=right[0];i!=0;i=right[right[i]])
				ans += i;
		else
			for(int i=left[0];i!=0;i=left[left[i]])
				ans += i;
		printf("%lld\n",ans);
	}
}
