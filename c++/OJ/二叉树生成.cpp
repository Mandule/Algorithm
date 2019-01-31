#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char str1[30];
char str2[30];
char str3[30];

struct Node{
	Node* left;
	Node* right;
	char val;
}node[30];
int size=0;
int j=0;

Node* creat(char val){
	node[size].val =val;
	node[size].left=node[size].right=NULL;
	return &node[size++];
}

Node* BuildTree(char* str1,char* str2,int s1,int e1,int s2,int e2){
	if(s1>e1 || s2>e2) return NULL;
	Node* root = creat(str1[s1]);
	int i=s2;
	for(i;i<=e2;i++){
		if(str2[i]==str1[s1]) break;
	}
	if(i==s2){
		root->right = BuildTree(str1,str2,s1+1,e1,s2+1,e2);
	}else
	if(i==e2){
		root->left = BuildTree(str1,str2,s1+1,s1+e2-s2,s2,e2-1);
	}
	else{
		root->left = BuildTree(str1,str2,s1+1,s1+i-s2,s2,i-1);
		root->right = BuildTree(str1,str2,s1+i-s2+1,e1,i+1,e2);
	}
	return root;
}

void postOrder(Node* root){
	if(root->left!=NULL) postOrder(root->left);
	if(root->right!=NULL) postOrder(root->right);
	str3[j++] = root->val;
}


int main(){
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		j=0;
		size=0;
		Node * root = BuildTree(str1,str2,0,strlen(str1)-1,0,strlen(str2)-1);
		postOrder(root);
		cout<<str3<<endl;
	}
	return 0;
}
