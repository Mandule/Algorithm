#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

string str;
set<char> s;

bool isSame(char c1,char c2){
	if(s.count(c1) == s.count(c2)) return true;
	else return false;
}

bool solve(string str){
	int a = str.find_first_of("aeiou");
	if(a == -1) return false;
	int n = 1;
	for(int i=1;i<str.size();i++){
		if(isSame(str[i],str[i-1])) n++;
		else n = 1;
		if(n == 3) return false;
		if(str[i] == str[i-1])
			if(str[i]!='e' && str[i]!='o')
				return false; 
	}
	return true;
}


int main(){
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	while(cin>>str && str!="end"){
		if(solve(str))
			cout<<"<"+str+"> "<<"is acceptable."<<endl;
		else 
			cout<<"<"+str+"> "<<"is not acceptable."<<endl;
	}
    return 0;
}