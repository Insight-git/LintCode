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

/*solution 1 递归方法*/
class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        static vector<int> list;
        if(!root)
        	return list;
        inorderTraversal(root->left);
        list.push_back(root->val);
        inorderTraversal(root->right);
        return list;
    }
};

/*solution 2 迭代方法*/
class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> list;
        stack<TreeNode*> s;
        TreeNode *node = root;
        if(!root)
        	return list;
        while(1)
        {
        	for(;node;node=node->left)
        	{
        		s.push(node);
        	}
        	if(s.empty())
        		break;
        	node = s.top();
        	s.pop();
        	list.push_back(node->val);
        	node = node->right;
        }
        return list;
    }
};