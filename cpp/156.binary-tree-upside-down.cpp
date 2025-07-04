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
 * left -> root
 * root ->right
 * right -> left
 */
class Solution {
public:
    TreeNode *dfs(TreeNode *current){
	 if(!current)return NULL;
	 if(!current->left && !current->right) return current;
	 auto new_root = dfs(current->left);
	 current->left->left = current->right;
	 current->left->right = current;
	 return new_root;
    }
    TreeNode* solve(TreeNode *root){
	    if(!root)return root;
	    auto res = dfs(root);
	    root->left=NULL;
	    root->right=NULL;
	    return res;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
	    return solve(root);
    }
};
