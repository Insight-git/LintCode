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
     * @param A: an integer array
     * @return: A tree node
     */
	TreeNode *BuildTree(vector<int> &A, int start, int end)
	{
		if(start > end)
			return NULL;
		int mid = start + (end - start) / 2;
		TreeNode *root = new TreeNode(A[mid]);
		root->left = BuildTree(A,start,mid-1);
		root->right = BuildTree(A,mid+1,end);
		return root;
	}
    TreeNode * sortedArrayToBST(vector<int> &A) {
    	unsigned int num_node = A.size();
        if(!num_node)
        	return NULL;
        return *BuildTree(A,0,num_node-1);
    }
};