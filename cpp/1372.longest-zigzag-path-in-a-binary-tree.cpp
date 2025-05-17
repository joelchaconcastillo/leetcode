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
    #define ROOT -1
    #define LEFT 0
    #define RIGHT 1
    map<tuple<TreeNode*, int>, int> memo; // node, 2
    //// time: O(n)
    ///  space: O(n*2) ~ O(n)
    ///  
    int dfs(TreeNode *current, int prev=-1){
	   if(!current) return -1;
           if(memo.count({current, prev}))return memo[{current, prev}];
	   int res = 0;
	   if(prev == RIGHT)  res = dfs(current->left, LEFT)+1;
	   else if(prev == LEFT)  res = dfs(current->right, RIGHT)+1;
	   else{
	     res = max(res, dfs(current->left, LEFT)+1);
	     res = max(res, dfs(current->right, RIGHT)+1);
	   }
	   return memo[{current, prev}] = res;
    }
    int solve1(TreeNode *root){
	memo.clear();
	queue<TreeNode *> q;
	q.push(root);
	int res = 0;
	while(!q.empty()){
	     auto current = q.front(); q.pop();
	     if(!current)continue;
	     q.push(current->left);
	     q.push(current->right);
	     res = max(res, dfs(current));
	}
	return res;
    }
    ///////////////////////// 
    ///time: O(n)
    ///space: O(n)
    typedef tuple<int, int, int> my_type;
    my_type dfs2(TreeNode *current){
	   if(!current) return {-1, -1, 0};

	   auto [leftz1, leftz2, leftMax] = dfs2(current->left);
           auto [rightz1, rightz2, rightMax] = dfs2(current->right);
	   
	   return {leftz2+1, rightz1+1, max({leftz2+1, rightz1+1, leftMax, rightMax})};
    }
    int solve2(TreeNode* root){
	    auto [_, _, res] = dfs2(root);
	    return res;
    }
    int longestZigZag(TreeNode* root) {
	return solve1(root);
//	return solve2(root);
    }
};
