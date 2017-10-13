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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        queue<TreeNode*> q1;
		vector<vector<int>> all_node;
		vector<int> level_node;
		if (!root)
			return all_node;
		q1.push(root);
		while (!q1.empty())
		{
			queue<TreeNode*> q2;
			while(1)
			{
				TreeNode *node = q1.front();
				q1.pop();
				if(node->left)
					q2.push(node->left);
				if(node->right)
					q2.push(node->right);
				level_node.push_back(node->val);
				if(q1.empty())
				{
					all_node.push_back(level_node);
					level_node.clear();
					break;
				}
			}
			q1 = q2;
		}
		return all_node;
    }
};