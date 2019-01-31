/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cmath>

class Solution {
	public:
		int ans = 0;
    	int diameterOfBinaryTree(TreeNode* root) {
    		if(root == NULL)
    			return 0;
    		getHigh(root);
    		return ans;
    	}

    	int getHigh(TreeNode* root){
    		if(root == NULL) 
    			return 0;
    		int left = getHigh(root->left);
    		int right = getHigh(root->right);

    		ans = max(ans,left+right); //计算高度的同时更新直径长度
    		
    		return max(left,right)+1;
    	}
};