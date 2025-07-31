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
    void traversal(TreeNode* current, int level, unordered_map<TreeNode*, TreeNode*> &parents, unordered_map<TreeNode*, int>  &levels, TreeNode *parent){
	    if(!current) return;
	    parents[current] = parent;
	    levels[current] = level;

	    traversal(current->left, level+1, parents, levels, current);
	    traversal(current->right, level+1, parents, levels, current);
    }
    TreeNode * LCA(TreeNode * a, TreeNode *b, unordered_map<TreeNode*, int> &levels, unordered_map<TreeNode*, TreeNode*> &parents){
	    if(levels[a]<levels[b])swap(a,b);
	    while(levels[a] > levels[b]) a = parents[a];
	    while(a!=b){
		    a = parents[a];
		    b = parents[b];
	    }
	    return a;
    } 
    // sol =  depth[p] + dept[q] - 2*depth[LCA(p,q)]
    int solve(TreeNode* root, int p, int q){
	    unordered_map<TreeNode *, TreeNode*>parents;
	    unordered_map<TreeNode*, int> levels;
	    TreeNode *p_pointer, *q_pointer;
	    //fill al the data
	    traversal(root, 0, parents, levels, NULL);

	    for(auto &[node, level]:levels){
		    if(node->val == p) p_pointer = node;
		    if(node->val == q) q_pointer = node;
	    }
	   // TreeNode *_lca_p_q = LCA(p_pointer, q_pointer, levels, parents);
	    TreeNode *_lca_p_q = find_LCA(root, p, q);
	    return levels[p_pointer]+levels[q_pointer] - 2*levels[_lca_p_q];
    }
    TreeNode* find_LCA(TreeNode *current, int p, int q){
	    if(!current) return NULL;
	    TreeNode *left=NULL, *right=NULL;
	    if(current->val == p || current->val == q)return current;
	    if(current->left) left = find_LCA(current->left,p, q);
	    if(current->right) right = find_LCA(current->right,p, q);
	    if(left && right) return current;
	    if(left)return left;
	    return right;
    }

    int findDistance(TreeNode* root, int p, int q) {
	    return solve(root, p, q);
    }
};
