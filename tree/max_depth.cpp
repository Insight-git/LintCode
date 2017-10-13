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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
    	int left_depth = 0;
    	int right_depth = 0;
        if(!root)
        	return 0;
        if(!root->left&&!root->right)
        	return 1;
        if(root->left)
        	left_depth = maxDepth(root->left);
        else
        	left_depth = INT_MIN;
        if(root->right)
        	right_depth = maxDepth(root->right);
        else
        	right_depth = INT_MIN;
        return max(left_depth,right_depth)+1;
    }
};