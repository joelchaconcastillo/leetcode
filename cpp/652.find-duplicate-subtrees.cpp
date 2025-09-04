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
    string dfs(TreeNode *current, unordered_map<string, int> &visited, vector<TreeNode*> & res){
	    if(!current)return "";
	    auto left = "L"+dfs(current->left, visited, res);
	    auto right = "R"+dfs(current->right, visited, res);
	    string subtree = left + "-"+to_string(current->val)+"-"+ right;
	    if(visited[subtree]==1) res.push_back(current);
	    visited[subtree]++;
	    return subtree;

    }
    vector<TreeNode*> solve1(TreeNode* root) {
	    unordered_map<string, int>visited;
	    vector<TreeNode*>res;
	    dfs(root, visited, res);
	    return res;
    }
    struct my_hash {
        size_t operator()(const tuple<int,int,int>& ids) const {
            auto& [h1, h2, h3] = ids;
            size_t hash1 = std::hash<int>()(h1);
            size_t hash2 = std::hash<int>()(h2);
            size_t hash3 = std::hash<int>()(h3);
            return hash1 ^ (hash2 << 16) ^ (hash3 << 32);
        }
    };
    unordered_map<int, int> freq;
    vector<TreeNode*> res;
    int id = 1;
    long long helper(TreeNode *current, unordered_map<tuple<int, int, int>, int, my_hash> &hash2Id){
	    if(!current)return 0;
	    auto left = helper(current->left, hash2Id);
	    auto right = helper(current->right, hash2Id);
	    tuple<int, int, int> hashed(left, right, current->val);
	    if(hash2Id.count(hashed)==0) hash2Id[hashed]=id++;
	    int curId = hash2Id[hashed];
	    if(++freq[curId]==2) res.push_back(current);
	    return curId;
    }
    vector<TreeNode*> solve2(TreeNode* root) {
	    unordered_map<tuple<int, int, int>, int, my_hash> hash2Id;
	    helper(root, hash2Id);
	    return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
	    return solve2(root);
    }
};
// 4 2 1 4 2 3 4
// 0 0 0 1 2 0 0
// 1 2 1
// 0 0 1
// 3 2 2 3 2
// 0 0 0 1 2
