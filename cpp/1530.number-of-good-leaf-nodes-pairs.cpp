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
    void traverse(TreeNode* current, unordered_map<TreeNode*, TreeNode*> &parents, unordered_map<TreeNode*, int> &depth, int level, TreeNode* parent, vector<TreeNode*> &leafs){
	    if(!current)return;
	    if(!current->left && !current->right) leafs.push_back(current);
	    parents[current] = parent;
	    depth[current] = level;
	    traverse(current->left, parents, depth, level+1, current, leafs);
	    traverse(current->right, parents, depth, level+1, current, leafs);
    }
    TreeNode *find_LCA(TreeNode *a, TreeNode* b, unordered_map<TreeNode *, TreeNode*> &parents, unordered_map<TreeNode* , int> &depth){
	    if(depth[a] < depth[b]) swap(a,b);
	    while(depth[a] > depth[b]) a = parents[a];
	    while(a!=b){
		    a = parents[a];
		    b = parents[b];
	    }
	    return a;
    }
    int solve(TreeNode *root, int distance){
	    unordered_map<TreeNode*, TreeNode*> parents;
	    unordered_map<TreeNode*, int> depth;
	    vector<TreeNode*> leafs;
	    traverse(root, parents, depth, 0, NULL, leafs);
	    int n = leafs.size();
	    int res = 0;
	    for(int i = 0 ;i  < n ;i++){
		    for(int j = i+1; j < n; j++){
			    auto &leaf_a = leafs[i];
			    auto &leaf_b = leafs[j];
			    long long dist = depth[leaf_a] + depth[leaf_b] - 2*depth[find_LCA(leaf_a, leaf_b, parents, depth)];
			    if(dist<=distance) res++;
		    }
	    }
	    return res;
    }
    vector<int> postOrder(TreeNode *current, int distance, int &res){
	    if(!current) return vector<int> (11, 0);
	    if(!current->left && !current->right){
		    vector<int> tmp(11,0);
		    tmp[0]=1;
		    return tmp;
	    }
	    auto left = postOrder(current->left, distance, res);
	    auto right = postOrder(current->right, distance, res);
	    vector<int> current_distances(11,0);
	    for(int i = 0; i < 10; i++){
		    current_distances[i+1] = left[i]+right[i];
	    }
	    int sum = 0, i = 0;
	    for(int j = distance-2; j>=0; j--){
		    sum += left[i++];
		    res += sum*right[j];
	    }
//	    for(int i = 0; i <= distance; i++){
//		    for(int j = 0; i+j+2 <= distance; j++){
//				    res += left[i]*right[j];
//		    }
//	    }
	    return  current_distances;
    }
    int solve2(TreeNode *root, int distance){
	    int res=0;
	    postOrder(root, distance, res);
	    return res;
    }
    int countPairs(TreeNode* root, int distance) {
	    return solve2(root, distance);
	    return solve(root, distance);
    }
};
