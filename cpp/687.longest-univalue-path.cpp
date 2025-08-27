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
    int res = 0;
    int helper(TreeNode *current){
	    if(!current)return 0;
	    int left = helper(current->left);
	    int right = helper(current->right);
	    if(current->left && current->left->val != current->val) left=0;
	    if(current->right && current->right->val != current->val) right=0;
	    res = max(res, left+right+1);
	    return max(left+1, right+1);
    }
    int longestUnivaluePath(TreeNode* root) {
	    helper(root);
	    return max(0, res-1);
    }
};
