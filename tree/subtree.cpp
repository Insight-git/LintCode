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
    void PreOrderTraverse(TreeNode *T1, TreeNode *T2, bool &result)
    {
        if(!T1&&!T2)
        	return;
        if((!T1&&T2)||(!T2&&T1))
        {
        	result = false;
        	return;
        }
        if(T1->val==T2->val)
        {
        	result = true;
        	PreOrderTraverse(T1->left,T2->left,result);
        	PreOrderTraverse(T1->right,T2->right,result);
        	return;
        }
        else
        {
        	result = false;
        	PreOrderTraverse(T1->left,T2,result);
        	PreOrderTraverse(T1->right,T2,result);
        	return;
        }
    }
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        bool result = true;
        if(!T2)
            return true;
        PreOrderTraverse(T1,T2,result);
        return result;
    }
};