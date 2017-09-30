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

//Version 1
class Solution {
public:
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: 
     */
	vector<int> PreOrderTraverse(TreeNode *root)
	{
		static vector<int> node_value;
		if(!root)
			return node_value;
		node_value.push_back(root->val);
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
		delete root;
		return node_value;
	}
    void flatten(TreeNode * root) {
    	vector<int> node_value;
    	TreeNode *p = root;
    	node_value = PreOrderTraverse(root);
    	if(node_value.size()>0)
    	{
	    	auto it=node_value.begin();
	    	p->val = *it;
	    	p->left = NULL;
	    	for(it=node_value.begin()+1;it!=node_value.end();it++)
	    	{
	    		TreeNode *s = new TreeNode;
	    		s->val = *it;
	    		s->left = NULL;
	    		p->right = s;
	    		p = s;
	    	}
	    	p->right = NULL;
    	}
    }
};

//Version 2
class Solution {
private:
	TreeNode *last_node = NULL;
public:
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: 
     */
    void flatten(TreeNode * root) 
    {
    	if(!root)
    		return;
    	if(last_node)
    	{
    		last_node->left = NULL;
    		last_node->right = root;
    	}
    	last_node = root;
    	TreeNode *right = root->right;//保存根结点的右孩子指针
    	flatten(root->left);
    	flatten(right);
    }
};