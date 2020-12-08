#include <cstdio>
#include <cmath>
#include <iostream>
#define ISYEAP(x) x%100!=0 && x%4==0 || x%400==0 ? 1:0
using namespace std;
int dayofMonth[13][2]={
	0,0, 
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};

struct data{
	int year;
	int month;
	int day;
	void nextDay(){
		day++;
		if(day>dayofMonth[month][ISYEAP(year)]){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
};

int buf[3001][13][32];

int main(){
	data tmp;
	tmp.year=0;
	tmp.month=1;
	tmp.day=1;
	int n=0;
	while(tmp.year!=3001){
		buf[tmp.year][tmp.month][tmp.day]=n;
		tmp.nextDay();
		n++; 
	}
	int year1,month1,day1;
	int year2,month2,day2;
	while(scanf("%4d%2d%2d",&year1,&month1,&day1)){
		scanf("%4d%2d%2d",&year2,&month2,&day2);
		printf("%d\n",abs(buf[year1][month1][day1]-buf[year2][month2][day2]));
	}
}




