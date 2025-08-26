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
    int dfs(TreeNode *current, int num){
	    if(!current)return 0;
	    num <<=1;
	    if(current->val==1)num|=1;
	    if(!current->left && !current->right) return num;
	    return dfs(current->left, num)+dfs(current->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
	    return dfs(root, 0);
    }
};
