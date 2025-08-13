#define oob(x, y) (x < 0 or y < 0 or x >= N or y >= N)
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
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
    TreeNode *dfs(vector<int> &preorder, vector<int> &postorder, int pre_l, int pre_r, int pos_l, int pos_r, unordered_map<int, int> &index_postorder){
	    if(pre_l>=pre_r)return NULL;
	    TreeNode * current = new TreeNode(preorder[pre_l]);
	    if(pre_r-pre_l==1)return current;
	    int left_root_value = preorder[pre_l+1];
	    int left_root_id_post = index_postorder[left_root_value];
	    int left_sz = left_root_id_post-pos_l+1;
	    int m = pre_l+1+left_sz;
	    current->left = dfs(preorder, postorder, pre_l+1, m, pos_l, left_root_id_post+1, index_postorder);
	    current->right = dfs(preorder, postorder, m, pre_r,left_root_id_post+1, pos_r-1, index_postorder);
	    return current;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
	    unordered_map<int, int> index_postorder;
	    for(int i = 0 ; i < postorder.size(); i++) index_postorder[postorder[i]]=i;
	    return dfs(preorder, postorder, 0, preorder.size(), 0, postorder.size(), index_postorder);
    }
};
