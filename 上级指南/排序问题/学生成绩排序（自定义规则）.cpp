#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

struct Student{
	char 	name[100];
	int 	age;
	int 	score;
}buf[1000];
bool cmp(Student s1,Student s2){
	if(s1.score!=s2.score){
		return s1.score<s2.score;
	}
	int tmp = strcmp(s1.name,s2.name);
	if(tmp!=0){
		return tmp<0;
	}
	return s1.age<s2.age;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",&buf[i].name,&buf[i].age,&buf[i].score);
		}
		sort(buf,buf+n,cmp);
		for(int i=0;i<n;i++){
			cout<<buf[i].name<<" "<<buf[i].age<<" "<<buf[i].score<<endl;
		}
	}
	return 0;
}
