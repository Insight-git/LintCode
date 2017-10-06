/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
    	int left_depth = 0;
    	int right_depth = 0;
        if(!root)
        	return 0;
        if(!root->left&&!root->right)
        	return 1;
        if(root->left)
        	left_depth = minDepth(root->left);
        else
        	left_depth = INT_MAX;
        if(root->right)
        	right_depth = minDepth(root->right);
        else
        	right_depth = INT_MAX;
        return min(left_depth,right_depth)+1;
    }
};