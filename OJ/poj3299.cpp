#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;


int main(){
	float T,D,H,E; 
	char tmp1,tmp2;
	while(true){
		scanf("%c",&tmp1);
		if(tmp1=='E') break;
		getchar();
		scanf("%f %c %f",&T,&tmp2,&D);
		getchar();
		E = 6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
		H = 0.5555*(E-10.0);
		printf("%c %.1f %c %.1f %c %.1f\n",'T',T,'D',D,'H',T+H);
		
	}
	return 0;
} 
