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
    unordered_map<int, int> levels, parents;
    void dfs(TreeNode* root, int level, int parent){
	    if(!root)return;
	    levels[root->val] = level;
	    parents[root->val] = parent;
	    dfs(root->left, level+1, root->val);
	    dfs(root->right, level+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, -1);
        return levels[x] == levels[y] && parents[x]!=parents[y];	
    }
};
