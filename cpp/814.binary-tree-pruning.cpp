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
    pair<int, TreeNode*> dfs(TreeNode* current){
	    if(!current) return {0, NULL};
	    auto [left_cont, left_ptr] = dfs(current->left);
	    auto [right_cont, right_ptr] = dfs(current->right);
	    int sum = left_cont+right_cont+current->val;
	    current->left = left_ptr;
	    current->right = right_ptr;
	    if(sum==0)return {0,NULL};
	    return {sum, current};
    }
    TreeNode* dfs2(TreeNode *current){
	    if(!current)return NULL;
	    current->left = dfs2(current->left);
	    current->right = dfs2(current->right);
	    if(!current->left && !current->right && current->val==0)return NULL;
	    return current;
    }
    TreeNode* pruneTree(TreeNode* root) {
	    return dfs2(root);
	    return dfs(root).second;
    }
};
