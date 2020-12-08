#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

map<string,string> Map;
set<char> Set;

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	Set.insert('a');
	Set.insert('e');
	Set.insert('i');
	Set.insert('o');
	Set.insert('u');
    int n,l;
    cin>>n>>l;
    while(n--){
    	string str1;
    	string str2;
    	cin>>str1>>str2;
    	Map[str1] = str2;
    }
    while(l--){
    	string str;
    	cin>>str;
    	if(Map.count(str)) cout<<Map[str]<<endl;
    	else{
    		string tmp = str.substr(str.size()-2);
    		if(tmp[1] == 'y' && !Set.count(tmp[0])) str.replace(str.size()-1,1,"ies");
    		else if(tmp[1] == 'o' || tmp[1] == 's' || tmp[1] == 'x' || tmp == "ch" || tmp == "sh")
    			str.append("es");
    		else
    			str.append("s");
    		cout<<str<<endl;
    	}
    }
    return 0;
}












