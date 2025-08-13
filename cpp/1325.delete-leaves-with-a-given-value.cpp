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
    TreeNode * helper(TreeNode* current, int target){
	    if(!current)return NULL;
	    current->left = helper(current->left, target);
	    current->right = helper(current->right, target);
	    if(!current->left && !current->right &&
			    current->val == target){
			    return NULL;
	    }
	    return current;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
	    return helper(root, target);
    }
};
