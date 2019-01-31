#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int loc;
struct tNode{
	tNode *left;
	tNode *right;
	int val;
}Node[250];

tNode *creat(int val){
	Node[loc].left=NULL;
	Node[loc].right=NULL;
	Node[loc].val = val;
	return &Node[loc++];
}
char str1[10];
char str2[10];

char pre1[10];
char pre2[10];
char in1[10];
char in2[10];

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

void preOrder(tNode *root,char *ch,int i){
	ch[i++] = (char)(root->val+'0');
	if(root->left!=NULL){
		preOrder(root->left,ch,i);
	}
	if(root->right!=NULL){
		preOrder(root->right,ch,i);
	}
}
void inOrder(tNode *root,char *ch,int i){
	if(root->left!=NULL){
		inOrder(root->left,ch,i);
	}
	ch[i++] = (char)(root->val+'0');
	if(root->right!=NULL){
		inOrder(root->right,ch,i);
	}
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		loc = 0;
		scanf("%s",&str1);
		tNode *root1 = creat(str1[0]-'0');
		for(int i=1;i<strlen(str1);i++){
			int tmp = str1[i]-'0';
			build(root1,tmp);
		}
		
		preOrder(root1,pre1,0);
		inOrder(root1,in1,0);
		
		for(int i=0;i<n;i++){
			scanf("%s",&str2);	
			tNode *root2=creat(str2[0]-'0');
			for(int j=1;j<strlen(str2);j++){
				int tmp = str2[j]-'0';
				build(root2,tmp);
			}
			preOrder(root2,pre2,0);
			inOrder(root2,in2,0);
			if(strcmp(pre1,pre2) == 0 && strcmp(in1,in2) == 0){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
		for(int i=0;i<n;i++){
			pre1[i]=pre2[i]=' ';
			in1[i]=in2[i]=' ';
		}
	}
	return 0;
}

