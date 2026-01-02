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
    bool _find(int target, TreeNode* current){
	    if(!current)return false;
	    if(current->val==target)return true;
	    if(current->val < target) return _find(target, current->right);
	    return _find(target, current->left);
    }
    bool dfs(TreeNode *current, TreeNode* root, int target){
	    if(!current)return false;
	    if(_find(target-current->val, root))return true;
	    return dfs(current->left, root, target) ||
		    dfs(current->right, root, target);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
	    return dfs(root1, root2, target);
    }
};
