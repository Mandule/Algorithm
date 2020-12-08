#include <cstdio>
#include <iostream>
using namespace std;
int loc;
struct tNode{
	tNode *left;
	tNode *right;
	int val;
}Node[100];

tNode *creat(int val);
void build(tNode *root,int val);
void preOrder(tNode *root);
void inOrder(tNode *root);
void postOrder(tNode *root);

int main(){
	int n; 
	while(scanf("%d",&n)!=EOF){
		int loc = 0;
		int val;
		cin>>val;
		tNode *root = creat(val);
		for(int i=1;i<n;i++){
			cin>>val;
			build(root,val);
		}
		preOrder(root);
		cout<<endl;
		inOrder(root);
		cout<<endl;
		postOrder(root);
		cout<<endl;
	}
	return 0;
}
void build(tNode *root,int val){
	if(val < root->val){
		if(root->left == NULL){
			root->left = creat(val);
			return;
		}
		else{
			build(root->left,val);
		}
	}
	else if(val > root->val){
		if(root->right == NULL){
			root->right = creat(val);
			return;
		}else{
			build(root->right,val);
		}
	}else{
		return;
	}
}

tNode *creat(int val){
	Node[loc].left=NULL;
	Node[loc].right=NULL;
	Node[loc].val = val;
	return &Node[loc++];
}
void preOrder(tNode *root){
	cout<<root->val<<" ";
	if(root->left!=NULL){
		preOrder(root->left);
	}
	if(root->right!=NULL){
		preOrder(root->right);
	}
}
void inOrder(tNode *root){
	if(root->left!=NULL){
		inOrder(root->left);
	}
	cout<<root->val<<" ";
	if(root->right!=NULL){
		inOrder(root->right);
	}
}
void postOrder(tNode *root){
	if(root->left!=NULL){
		postOrder(root->left);
	}
	if(root->right!=NULL){
		postOrder(root->right);
	}
	cout<<root->val<<" ";
}
