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
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) 
    {
        static vector<vector<int>> all_path;
        static vector<int> path;
        int remain = 0;
        if(!root)
        	return all_path;
        path.push_back(root->val);
        if(root->val==target&&!root->left&&!root->right)//叶子结点，并且路径长度刚好满足
        {
        	all_path.push_back(path);
        	path.pop_back();//去掉当前的叶子结点
        	return all_path;
        }
        else if(!root->left&&!root->right)//叶子结点，路径长度不满足
        {
        	path.pop_back();//去掉当前的叶子结点
        	return all_path;
        }
        remain = target - root->val;
        binaryTreePathSum(root->left, remain);
        //path.pop_back();
        binaryTreePathSum(root->right, remain);
        path.pop_back();//去掉父节点
        return all_path;
    }
};