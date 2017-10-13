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

/*solution 1 递归方式*/
class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        static vector<int> list;
        if(!root)
        	return list;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        list.push_back(root->val);
        return list;
    }
};

/*solution 2 迭代方式*/
class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> list;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        if(!root)
            return list;
        while(1)
        {
            for(;cur;cur=cur->left)
            {
                s.push(cur);
            }
            TreeNode *top_node = s.top();
            if((top_node->right)&&(pre!=top_node->right))
            {
                cur = top_node->right;
            }
            else
            {
                list.push_back(top_node->val);
                pre = top_node;
                s.pop();
            }
            if(s.empty())
                break;
        }
        return list;
    }
};