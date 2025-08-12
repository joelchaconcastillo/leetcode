/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* current, TreeNode* tmp){
	    if(!current)return tmp;
	    TreeNode * res = NULL;
	    res = helper(current->left, current);
	    current->left = NULL;
	    current->right = helper(current->right, tmp);
	    return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
	    return helper(root, NULL);
    }
};
