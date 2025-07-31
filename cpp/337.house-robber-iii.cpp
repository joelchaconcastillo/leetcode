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
    vector<int> helper(TreeNode *current){
	    if(!current) return {0,0};
	    if(!current->left && !current->right) return {0,current->val};
	    auto left = helper(current->left);
	    auto right = helper(current->right);
	    return {
		    left[1]+right[1],
		    max(
			    left[1]+right[1],
			    left[0]+right[0]+current->val
		      )
	    };
    }
    int solve(TreeNode* current){
	    auto res = helper(current);
	    return max(res[0], res[1]);
    }
    int rob(TreeNode* root) {
	    return solve(root);
    }
};
