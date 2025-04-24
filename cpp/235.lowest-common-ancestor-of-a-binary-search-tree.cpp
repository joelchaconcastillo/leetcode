/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

public:
    unordered_map<TreeNode*, TreeNode*>parents;
    unordered_map<TreeNode*, int> levels;
    void dfs(TreeNode *current, TreeNode *parent, int level){
	 if(!current)return;
	 levels[current] = level;
	 parents[current] = parent;
	 dfs(current->left, current, level+1);
	 dfs(current->right, current, level+1);
    }
    TreeNode *solve1(TreeNode *root, TreeNode *p, TreeNode*q){
	    dfs(root, NULL, 0);
	    while(p && levels[p] > levels[q]) p = parents[p];
	    while(q && levels[p] < levels[q]) q = parents[q];
	    while(p && q && p != q)p=parents[p], q=parents[q];
	    return p;
    }
    TreeNode* find_lca(TreeNode *root, TreeNode *p, TreeNode *q){
	    if(root->val < p->val && root->val < q->val)
		    return find_lca(root->right, p, q);
	    else if(root->val > p->val && root->val > q->val)
		    return find_lca(root->left, p ,q);
	    return root;
    }
    TreeNode *solve2(TreeNode *root, TreeNode *p, TreeNode*q){
	    return find_lca(root, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	  return solve2(root, p, q);
    }
};
