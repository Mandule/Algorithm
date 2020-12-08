#include <stdio.h>
int dayofMonth[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};

class Data{
	public:
		Data(int year,int month,int day){
			Year = year;
			Month = month;
			Day = day;
		}
		void nextDay(){
			Day++;
			if(Day>dayofMonth[Month][isYear()]){
				Day = 1;
				Month++;
				if(Month>12){
					Month = 1;
					Year++;
				}
			}
		}
		int isYear(){
			return ((Year%100!=0 && Year%4==0)||(Year%400==0))?1:0;
		}
		bool operator < (const Data& t)const{
			if(Year<t.Year){
				return true;
			}
			else if(Year == t.Year){
				if(Month<t.Month){
					return true;
				}
				else if(Month == t.Month){
					if(Day<t.Day){
						return true;
					}
				}
			}
			return false;
		}
		bool operator == (const Data& t)const{
			if(Year==t.Year&&Month==t.Month&&Day==t.Day){
				return true;
			}
			return false;
		}
		bool operator != (const Data& t)const{
			if(Year==t.Year&&Month==t.Month&&Day==t.Day){
				return false;
			}
			return true;
		}
		bool operator > (const Data& t)const{
			if(Year>t.Year){
				return true;
			}
			else if(Year == t.Year){
				if(Month>t.Month){
					return true;
				}
				else if(Month == t.Month){
					if(Day>t.Day){
						return true;
					}
				}
			}
			return false;
		}
	private:
		int Day;
		int Month;
		int Year;
};

int main(){
	int y1,m1,d1;
	int y2,m2,d2;
	while(scanf("%4d%2d%2d\n%4d%2d%2d",&y1,&m1,&d1,&y2,&m2,&d2)!=EOF){
		Data t1(y1,m1,d1);
		Data t2(y2,m2,d2); 
		int ans = 0;
		if(t1 < t2){
			while(t1!=t2){
				ans++;
				t1.nextDay();
			}
		}
		else if(t2 > t1){
			while(t2!=t1){
				ans++;
				t2.nextDay();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

