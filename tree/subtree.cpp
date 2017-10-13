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
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
	bool IsIdentical(TreeNode *T1, TreeNode *T2)
	{
		static bool result = true;
		if(!T1&&!T2)
			return result;
		if((!T1&&T2)||(!T2&&T1))
		{
			result = false;
			return result;
		}
		if(T1->val!=T2->val)
		{
			result = false;
			return result;
		}
		IsIdentical(T1->left,T2->left);
		IsIdentical(T1->right,T2->right);
		return result;
	}
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        bool result = false;
        if(!T2)
            return true;
        if(T1->val==T2->val)
        {
        	result = IsIdentical(T1,T2);
        	if(result)
        		return result;
        }
        else
        {
        	isSubtree(T1->left, T2);
        	isSubtree(T1->right, T2);
        }
        return result;
    }
};