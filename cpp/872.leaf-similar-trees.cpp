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
    void dfs(TreeNode* current, vector<int> &res){
	    if(!current)return;
	    if(!current->left && !current->right){
		    res.push_back(current->val);
		    return;
	    }
	    dfs(current->left, res);
	    dfs(current->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	    vector<int> res1, res2;
	    dfs(root1, res1);
	    dfs(root2, res2);
	    return res1==res2;
    }
};
