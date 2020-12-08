#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct student{
	char name[100];
	int age;
	int score;
	bool operator < (const student &s)const{
		if(score!=s.score) return score<s.score;
		int tmp = strcmp(name,s.name);
		if(tmp!=0) return tmp<0;
		else return age<s.age;
	}
}s[1000];



int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",&s[i].name,&s[i].age,&s[i].score);
		}
		sort(s,s+n);
		for(int i=0;i<n;i++){
			printf("%s %d %d\n",s[i].name,s[i].age,s[i].score);
		}
	}
	return 0;
} 
