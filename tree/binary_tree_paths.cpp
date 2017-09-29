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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
    	static vector<string> all_path;
		static vector<int> path;
		if(!root)
        	return all_path;
        path.push_back(root->val);
        if(!root->left&&!root->right)//叶子结点
        {
        	auto it = path.begin();
        	string str;
    		for(;it!=path.end()-1;it++)
    		{
    			str = str + to_string(*it) + "->";
    		}
    		str = str + to_string(*it);
        	all_path.push_back(str);
        	path.pop_back();
        	return all_path;
        }
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);
        path.pop_back();
        return all_path;
    }
};