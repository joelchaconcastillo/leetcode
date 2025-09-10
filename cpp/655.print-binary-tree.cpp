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
    int maxDepth(TreeNode *root){
	    if(!root)return 0;
	    if(!root->left && !root->right) return 0;
	    return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    void dfs(TreeNode *current, vector<vector<string> > &mat, int row, int col){
	    if(!current)return;
	    mat[row][col] = to_string(current->val);
	    int n = mat.size();
	    if(row+1==n)return;
	    int delta = (1<<(n-row-2));
	    dfs(current->left, mat, row+1, col-delta);
	    dfs(current->right, mat, row+1, col+delta);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = maxDepth(root);
	int n = depth+1, m = (1<<(depth+1))-1;
        vector<vector<string> > mat(n, vector<string>(m));
	dfs(root, mat, 0, m/2);
	return mat;
    }
};
