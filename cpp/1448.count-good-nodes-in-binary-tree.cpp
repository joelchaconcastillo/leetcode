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
    int helper(TreeNode* current, int max_value){
	    if(!current)return 0;
	    int res = max_value <= current->val;
	    max_value = max(max_value, current->val);
	    res += helper(current->left, max_value);
	    res += helper(current->right, max_value);
	    return res;
    }
    int goodNodes(TreeNode* root) {
	    return helper(root, INT_MIN);
    }
};
