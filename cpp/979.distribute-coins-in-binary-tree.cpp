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
    int dfs(TreeNode *current, int &res){
	    if(!current) return 0;
	    int leftCoins = dfs(current->left, res);
	    int rightCoins = dfs(current->right, res);
	    res += abs(leftCoins)+abs(rightCoins);
	    return current->val-1+leftCoins+rightCoins;
    }
    int distributeCoins(TreeNode* root) {
	    int res = 0;
	    dfs(root, res);
	    return res;
    }
};
