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
        if(!T1&&!T2)
            return true;
        if((!T1&&T2)||(T1&&!T2))
        {
            return false;
        }
        if(T1->val != T2->val)
        {
            return false;
        }
        return (IsIdentical(T1->left, T2->left) && IsIdentical(T1->right, T2->right));
    }
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        if(!T2)
            return true;
        if(!T1)
            return false;
        if(IsIdentical(T1,T2))
            return true;
        if(isSubtree(T1->left, T2)||isSubtree(T1->right, T2))
            return true;
        return false;
    }
};