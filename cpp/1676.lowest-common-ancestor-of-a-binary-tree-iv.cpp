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
    void dfs(TreeNode* current, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &parents, unordered_map<TreeNode*, int> &level, int depth=0){
	    if(!current) return ;
	    parents[current]=parent;
	    level[current] = depth;
	    dfs(current->left, current, parents, level, depth+1);
	    dfs(current->right, current, parents, level, depth+1);
    }
    TreeNode * lca(TreeNode *a, TreeNode *b, unordered_map<TreeNode*, TreeNode* > &parents, unordered_map<TreeNode*, int> &level){
	    while(level[a] > level[b]) a = parents[a];
	    while(level[b] > level[a]) b = parents[b];
	    while(a!=b) a = parents[a], b = parents[b];
	    return a;
    }
    TreeNode* solve(TreeNode *root, vector<TreeNode*> &nodes){
	    int n = nodes.size();
	    if(n==0)return root;
	    if(n == 1) return nodes.front();
	    unordered_map<TreeNode*, TreeNode*> parents;
	    unordered_map<TreeNode*, int> level;
	    dfs(root, NULL, parents, level);
	    TreeNode * res = lca(nodes[0], nodes[1], parents, level);
	    for(int i = 2; i < n; i++){
		    res = lca(res, nodes[i], parents, level);
	    }
	    return res;
    }
    TreeNode* dfs2(TreeNode* current, unordered_set<TreeNode*> &nodes){
	    if(!current || nodes.count(current))return current;
	    auto left = dfs2(current->left, nodes);
	    auto right = dfs2(current->right, nodes);
	    if(left && right) return current;
	    if(left) return left;
	    return right;
    }
    TreeNode* solve2(TreeNode* root, vector<TreeNode*> &nodes) {
	    unordered_set<TreeNode*> nodes_(nodes.begin(), nodes.end());
	    return dfs2(root, nodes_);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
	    return solve2(root, nodes);
    }
};
