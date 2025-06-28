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
    
    vector<TreeNode *> solve(TreeNode *current, int target){
	    if(!current) return {NULL, NULL};
	    if(current->val > target){
		    auto _left = solve(current->left, target);
		    current->left = _left[1];
		    return {_left[0], current};
	    }else{
		    auto _right = solve(current->right, target);
		    current->right = _right[0];
		    return {current, _right[1]};
	    }
    }
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
	    return solve(root, target);
    }
};
