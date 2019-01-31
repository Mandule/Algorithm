#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

//OP + - * /
//   0 1 2 3

stack<int> op;
stack<double> num;

int M[][4] = {
	1,1,0,0,
	1,1,0,0,
	1,1,1,1,
	1,1,1,1
};

char str[201];

double getNumber(int &i,char* str){
	double ans=0;
	while(str[i]<='9' && str[i]>='0'){
		ans = (ans+(str[i]-'0'))*10;
		i++;
	}
	return ans/10;
}

int getOp(int &i,char* str){
	char op = str[i++];
	if(op=='+') return 0;
	if(op=='-') return 1;
	if(op=='*') return 2;
	else return 3;
} 

int main(){
	while(gets(str)){
		if(str[1]==0 && str[0]=='0') break;
		int i=0;
		while(i<strlen(str)){
			num.push(getNumber(i,str));
			if(i==strlen(str)) break;
			int tmpOp = getOp(i,str);
			if(op.empty()){
				op.push(tmpOp);
				continue;
			}
			while(!op.empty() && M[op.top()][tmpOp]==1){
				double b = num.top();
				num.pop();
				double a = num.top();
				num.pop();
				double ans;
				if(op.top()==0){
					ans = a+b;
				}else
				if(op.top()==1){
					ans = a-b;
				}else
				if(op.top()==2){
					ans = a*b;
				}else
				if(op.top()==3){
					ans = a/b;
				}
				num.push(ans);
				op.pop();
			}
			op.push(tmpOp);
		}
		double b=num.top();
		num.pop();
		double a=num.top();
		num.pop();
		double ans;
		if(op.top()==0){
			ans = a+b;
		}else
		if(op.top()==1){
			ans = a-b;
		}else
		if(op.top()==2){
			ans = a*b;
		}else
		if(op.top()==3){
			ans = a/b;
		}
		printf("%.2f\n",ans);
		op.pop();
	}
}
