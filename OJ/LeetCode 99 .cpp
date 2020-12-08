/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
	  TreeNode* pre= new TreeNode(INT_MIN),*first=NULL,*second=NULL;
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(first->val,second->val);
    }
    void inOrder(TreeNode* root){
    	if(root==NULL) 
    		return ;
    	inOrder(root->left);
    	if(pre->val > root->val){
   			if(first == NULL){
   				first = pre;
   				second = root;
   			}
   			else{
   				second = root;
   			}
   		}
    	pre = root;
    	inOrder(root->right);
    }
};