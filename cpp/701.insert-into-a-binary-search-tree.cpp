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
    TreeNode *solve(TreeNode *current, int val){
	    if(!current){
	      TreeNode *_new = new TreeNode(val);
	      return _new;
	    }
	    if(val <= current->val){
	      current->left = solve(current->left, val);
	    }
	    else{
	      current->right = solve(current->right, val);
	    }
	    return current;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
	   return solve(root, val);
    }
};
