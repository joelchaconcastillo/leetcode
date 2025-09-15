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
    unordered_map<int, vector<TreeNode*>> levels;
    unordered_map<TreeNode *, TreeNode*> parents;
    unordered_map<TreeNode*, int> _level;
    void dfs(TreeNode *current, int level, TreeNode* parent, int &maxLevel){
	    if(!current)return;
	    parents[current] = parent;
	    levels[level].push_back(current);
	    _level[current] = level;
	    maxLevel = max(maxLevel, level);
	    dfs(current->left, level+1, current, maxLevel);
	    dfs(current->right, level+1, current, maxLevel);
    }
    TreeNode* lca(TreeNode *a, TreeNode*b){
	    if(_level[a] < _level[b])swap(a,b);
	    while(_level[a] > _level[b] && parents[a]) a = parents[a];
	    while(a!=b && parents[a] && parents[b]){
		    a = parents[a];
		    b = parents[b];
	    }
	    return a;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
	    int maxLevel = 0;
	    dfs(root, 0, NULL, maxLevel);
	    TreeNode *all_lca = NULL;
	    for(auto &node:levels[maxLevel]){
		    if(!all_lca)all_lca=node;
		    else{
			    all_lca = lca(node, all_lca);
		    }
	    }
	    return all_lca;
    }
};
