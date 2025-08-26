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
    int helper(TreeNode* current, int &prev){
	    if(!current)return INT_MAX;
	    int left = helper(current->left, prev);
	    int diff = abs(current->val-prev);
	    prev = current->val;
	    int right = helper(current->right, prev);
	    return min({left, right, diff});
    }
    int minDiffInBST(TreeNode* root) {
	    int prev=100000;
	    return helper(root, prev);
    }
};
