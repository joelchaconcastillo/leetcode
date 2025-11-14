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
	    if(!current)return 0;
	    int left_val = dfs(current->left, res);
	    int right_val = dfs(current->right, res);
	    int current_val = current->val;
	    if((current_val == left_val || !current->left) && (current_val == right_val || !current->right)){
		    res++;
	    }else{
		    current_val = INT_MIN;
	    }
	    return current_val;
    }
    int countUnivalSubtrees(TreeNode* root) {
	int res=0;
	dfs(root, res);
	return res;
    }
};
