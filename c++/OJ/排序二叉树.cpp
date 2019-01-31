#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	Node* left;
	Node* right;
	int val;
}node[101];
int size=0;

Node* creat(int val){
	node[size].left=node[size].right=NULL;
	node[size].val = val;
	return &node[size++];
}

void AddNode(Node* root,int val){
	if(val>root->val){
		if(root->right!=NULL) AddNode(root->right,val);
		else root->right = creat(val);
	}else
	if(val<root->val){
		if(root->left!=NULL) AddNode(root->left,val);
		else root->left = creat(val);
	}
	else return;
}

void inOrder(Node* root){
	if(root->left!=NULL) inOrder(root->left);
	cout<<root->val<<' ';
	if(root->right!=NULL) inOrder(root->right);
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		size=0;
		int tmp;
		scanf("%d",&tmp);
		Node* root = creat(tmp);
		for(int i=1;i<n;i++){
			scanf("%d",&tmp);
			AddNode(root,tmp);
		}
		inOrder(root); 
	}
	return 0; 
} 
