#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

char str1[26];
char str2[26];

struct Node{
	Node* left;
	Node* right;
	char val;
}node[26];
int size=0;
Node* creat(char val){
	node[size].left = node[size].right = NULL;
	node[size].val = val;
	return &node[size++]; 
}

Node* buildTree(char* str1,char* str2,int s1,int e1,int s2,int e2){
	Node* root = creat(str1[s1]);
	if(s1 == e1 && s2 == e2) return root;
	int i;
	for(i=s2;i<=e2;i++)
		if(str2[i] == root->val) break; 
	if(i==s2)
		root->right = buildTree(str1,str2,s1+1,e1,s2+1,e2);
	else if(i==e2)
		root->left = buildTree(str1,str2,s1+1,e1,s2,e2-1);
	else{
		root->left = buildTree(str1,str2,s1+1,s1+i-s2,s2,i-1);
		root->right = buildTree(str1,str2,s1+i-s2+1,e1,i+1,e2);
	}
	return root;
}

void preOrder(Node* root){
	if(root->left!=NULL) preOrder(root->left);
	if(root->right!=NULL) preOrder(root->right);
	cout<<root->val;
}

int main(){
	while(scanf("%s%s",str1,str2)!=EOF){
		size=0;
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		Node* root = buildTree(str1,str2,0,len1-1,0,len2-1); 		
		preOrder(root);
		cout<<endl;
	}	
	return 0;
} 
