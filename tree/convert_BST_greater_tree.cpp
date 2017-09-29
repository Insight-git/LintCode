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
     * @param root: the root of binary tree
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
    	static int sum = 0;
    	int original_data = 0;
    	if(!root)
    		return root;
        convertBST(root->right);
        original_data = root->val;//保存结点原来的值
        root->val += sum;
        sum += original_data; 
        convertBST(root->left);
        return root;
    }
};