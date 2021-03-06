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
     * @param a: the root of binary tree a.
     * @param b: the root of binary tree b.
     * @return: true if they are identical, or false.
     */
    bool isIdentical(TreeNode * a, TreeNode * b) {
    	static bool result = true;
    	if(!a&&!b)
    	{
    		return result;
    	}
    	if(!a&&b)
    	{
    		result = false;
    		return result;
    	}
    	if(a&&!b)
    	{
    		result = false;
    		return result;
    	}
        if(a->val!=b->val)
        {
        	result = false;
        	return result;
        }
        isIdentical(a->left,b->left);
        isIdentical(a->right,b->right);
        return result;
    }
};