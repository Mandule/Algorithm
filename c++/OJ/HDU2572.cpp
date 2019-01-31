#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;


int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	int n;cin>>n;getchar();
 	string str,sub1,sub2;
 	while(n--){
 		vector< pair<int,int> > V1;
 		vector< pair<int,int> > V2;
 		getline(cin,str);getline(cin,sub1);getline(cin,sub2);
 		int i=0;
 		while(1){
 			i = str.find(sub1,i);
 			if(i==-1) break;
 			pair<int,int> tmp(i,i+sub1.size()-1);
 			V1.push_back(tmp);
 			i++;
 		}
 		i=0;
 		while(1){
 			i = str.find(sub2,i);
 			if(i==-1) break;
 			pair<int,int> tmp(i,i+sub2.size()-1);
 			V2.push_back(tmp);
 			i++;
 		}
 		if(V1.size()==0 || V2.size()==0){cout<<"No"<<endl;continue;}
 		int MIN = str.size();
 		int ans[2];
 		for(i=0;i<V1.size();i++){
 			int l1 = V1[i].first;
 			int r1 = V1[i].second;
 			for(int j=0;j<V2.size();j++){
 				int l2 = V2[j].first;
 				int r2 = V2[j].second;

 				int l = min(l1,l2);
 				int r = max(r1,r2);
 				int len = r-l+1;
 				if(len<MIN){
 					MIN = len;
 					ans[0] = l;
 					ans[1] = r;
 				}else if(len == MIN){
 					if(str.substr(l,len) < str.substr(ans[0],ans[1]-ans[0]+1)){
 						ans[0] = l;
 						ans[1] = r;
 					}
 				}
 			}
 		}
 		cout<<str.substr(ans[0],ans[1]-ans[0]+1)<<endl;
 	}
    return 0;
}














