class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root) 
    {
    	static TreeNode *max_node = root;
    	if(!root)
    		return max_node;
    	if(root->val>max_node->val)
    	{
    		max_node = root;
    	}
    	max_node = maxNode(root->left);
    	max_node = maxNode(root->right);
    	return max_node;       
    }
};