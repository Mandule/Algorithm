#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

struct Student{
	char 	name[100];
	int 	age;
	int 	score;
	bool operator < (const Student &s) const{
		if(score!=s.score){
		return score<s.score;
		}
		int tmp = strcmp(name,s.name);
		if(tmp!=0){
			return tmp<0;
		}
		return age<s.age;
	} 
}buf[1000];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",&buf[i].name,&buf[i].age,&buf[i].score);
		}
		sort(buf,buf+n);
		for(int i=0;i<n;i++){
			cout<<buf[i].name<<" "<<buf[i].age<<" "<<buf[i].score<<endl;
		}
	}
	return 0;
}
