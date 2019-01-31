#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
char str[200];
stack<double> in;
stack<int> op;
int cmp[][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};
bool isOption(int &num,int &i){
	if(i==0 && op.empty()==true || str[i]=='\0'){
		num = 0;
		return true;
	}
	if(str[i]<'0' || str[i]>'9'){
		switch(str[i]){
			case '+' : num=1;break;
			case '-' : num=2;break;
			case '*' : num=3;break;
			case '/' : num=4;break;
		}
		i=i+2;
		return true; 
	}
	num = 0;
	for(;str[i]!=' ' && str[i]!='\0';i++){
		num = num*10;
		num = num+str[i]-'0';
	}
	if(str[i]==' '){
		i++;
	}
	return false;
}

int main(){
	while(gets(str)){
		if(str[0]=='0' && str[1]=='\0'){
			break;
		}
		int num;
		int idx = 0;
		while(true){
			if(!isOption(num,idx)){
				in.push((double)num);
//				cout<<num<<"数入栈"<<endl;
			}
			else{
				if(op.empty()==true || cmp[num][op.top()]==1){
					op.push(num);
//					cout<<num<<"符号入栈"<<endl;
				}
				else{
					while(cmp[num][op.top()]==0){
						double tmp;
						double b = in.top();
						in.pop();
//						cout<<a<<"数字出栈"<<endl; 
						double a = in.top();
						in.pop();
//						cout<<b<<"数字出栈"<<endl;
						switch(op.top()){
							case 1 : tmp=a+b;break;
							case 2 : tmp=a-b;break;
							case 3 : tmp=a*b;break;
							case 4 : tmp=a/b;break;
						}
//						cout<<op.top()<<"符号出栈"<<endl; 
						op.pop();
						in.push(tmp);
//						cout<<tmp<<"数字入栈"<<endl; 
					}
					op.push(num);
//					cout<<num<<"符号入栈"<<endl;
				}
			}
			if(op.size()==2 && op.top()==0)break;
		}
		printf("%.2f\n",in.top());
		while(!op.empty())op.pop();
		while(!in.empty())in.pop();
	}
	return 0;
} 
