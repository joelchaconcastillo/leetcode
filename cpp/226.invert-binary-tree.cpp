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
    void solve(TreeNode *current){
	if(!current) return;
	solve(current->left);
	solve(current->right);
	swap(current->left, current->right);
    }
    TreeNode* invertTree(TreeNode* root) {
	    solve(root);
	    return root;
    }
};
