#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;


int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	string str;
	string ruler_name[n];
	vector<string> ruler[n];
	vector<string> url;
	for(int i=0;i<n;i++){
		cin>>str>>ruler_name[i];
		for(int j=0;j<str.size();j++){
			if(str[j] == '/'){
				str[j] = ' ';
				if(j == str.size()-1){
					str.append("/");
					break;
				}
			}
		}
		stringstream ss(str);
		while(ss>>str)
			ruler[i].push_back(str);
	}
	for(int i=0;i<m;i++){
		cin>>str;
		for(int j=0;j<str.size();j++){
			if(str[j] == '/'){
				str[j] = ' ';
				if(j == str.size()-1){
					str.append("/");
					break;
				}
			}
		}
		stringstream ss(str);
		url.clear();
		while(ss>>str)
			url.push_back(str);
		
		vector<string> par;
		int j;
		for(j=0;j<n;j++){
			bool match = true;
			par.clear();
			for(int k=0;k<ruler[j].size();k++){
				// cout<<"ruler"<<j<<endl;
				if(ruler[j][k] == "<int>"){
					// cout<<"<int>"<<endl;
					stringstream sstmp(url[k]);
					int tmp;
					if(sstmp>>tmp)
						par.push_back(to_string(tmp));
					else{
						match = false;
						break;
					}

				}
				else if(ruler[j][k] == "<str>"){
					// cout<<"<str>"<<endl;
					par.push_back(url[k]);
				}
				else if(ruler[j][k] == "/"){
					// cout<<"/"<<endl;
					if(url[k] != "/"){
						match = false;
						break;
					}
				}
				else if(ruler[j][k] == "<path>"){
					// cout<<"<path>"<<endl;
					if(url[url.size()-1] == "/"){
						match = false;
						break;
					}
					string tmp;
					for(int t=k;t<url.size();t++){
						tmp.append(url[t]);
						if(t != url.size()-1) tmp.append("/");
					}
					par.push_back(tmp);
				}
				else{
					// cout<<"------"<<endl;
					if(url[k] != ruler[j][k]){
						match = false;
						break;
					}
				}
			}
			if(match) break;
		}
		if(j == n) cout<<"404"<<endl;
		else{
			cout<<ruler_name[j]<<" ";
			for(int i=0;i<par.size();i++){
				cout<<par[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}