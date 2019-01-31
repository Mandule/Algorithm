#define LOCAL
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;


struct Node{
	int num;
	int val;
	Node* next[26];
}node[1<<20];
int size;

Node* newNode(int val){
	node[size].val = val;
	for(int i=0;i<26;i++) node[size].next[i] = NULL;
	node[size].num = 0;
	return &node[size++];
}

void inset_tree(Node* root,string str){
	Node* cur = root;
	for(int i=0;i<str.size();i++){
		int val = str[i]-'a';
		if(cur->next[val] == NULL){
			Node* n = newNode(val);
			n->num++;
			cur->next[val] = n;
		}
		else{
			Node* n = cur->next[val];
			n->num++;
		}
		cur = cur->next[val];
	}
}

int find_node(Node* root,string str){
	Node* cur = root;
	for(int i=0;i<str.size();i++){
		int val = str[i]-'a';
		if(cur->next[val] == NULL) return 0;
		cur = cur->next[val];
	}
	return cur->num;
}



int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt"
		,"w",stdout);
	#endif
	size = 0;
	Node* root = newNode(-1);
    string str;
    while(getline(cin,str) && str.size()!=0){
    	inset_tree(root,str);
    }
    while(getline(cin,str)){
    	cout<<find_node(root,str)<<endl;
    }
    return 0;
}