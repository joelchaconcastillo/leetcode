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
    vector<int> dfs(TreeNode *current, int &res){
	    if(!current)return {INT_MAX/2, INT_MIN/2};
	    if(!current->left && !current->right) return {current->val, current->val};
	    auto left = dfs(current->left, res);
	    auto right = dfs(current->right, res);
	    vector<int> min_max = {
		    min(left[0], right[0]),
		    max(left[1], right[1])
	    };
	    res = max({
			    res, 
			    abs(current->val-min_max[0]),
			    abs(current->val-min_max[1])
			    });
	    min_max = {min(current->val, min_max[0]), max(current->val, min_max[1])};
	    return min_max;
    }
    int solve(TreeNode *root){
	    int res=0;
	    dfs(root, res);
	    return res;
    }
    int maxAncestorDiff(TreeNode* root) {
	    return solve(root);
    }
};
