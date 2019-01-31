#include <stdio.h>
int dayofMonth[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};
int weekName[7]={6,0,1,2,3,4,5};
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
		int operator - (const Data& t)const{
			int ans = 0;
			Data t1(this->Year,this->Month,this->Day);
			Data t2(t.Year,t.Month,t.Day);
			if(t2<t1){
				while(t2!=t1){
					ans++;
					t2.nextDay();
				}
			}
			if(t2>t1){
				while(t2!=t1){
					ans--;
					t1.nextDay();
				}
			}
			return ans;
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
	int y,m,d;
	Data now(2018,5,12);
	while(scanf("%4d%2d%2d",&y,&m,&d)!=EOF){
		Data t(y,m,d);
		printf("%d\n",weekName[((t-now)%7+7)%7]);
	}
	return 0;
}

