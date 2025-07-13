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
    void dfs(TreeNode *current, long long &min1, long long &min2){
	    if(!current)return;
	    if(current->val < min1){
		    min2=min1;
		    min1=current->val;
	    }else if(current->val < min2 && current->val != min1){
		    min2 = current->val;
	    }
	    dfs(current->left, min1, min2);
	    dfs(current->right, min1, min2);
    }
    int solve(TreeNode *root){
	    long long min1=LLONG_MAX, min2=LLONG_MAX;
	    dfs(root, min1, min2);
	    if(min2==LLONG_MAX)return -1;
	    return min2;
    }
    int findSecondMinimumValue(TreeNode* root) {
	    return solve(root);
    }
};
