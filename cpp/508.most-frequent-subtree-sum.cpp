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
    unordered_map<long long, int>freq;
    long long solve(TreeNode * current){
	    if(!current)return 0;
	    long long left = solve(current->left);
	    long long right = solve(current->right);
	    long long sum = left+right+current->val;
	    freq[sum]++;
	    return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
	    vector<int> res;
	    solve(root);
	    int maxF=0;
	    for(auto [sum, count]:freq){
		    if(maxF < count){
			    maxF=count;
			    res = {(int)sum};

		    }else if(maxF==count)res.push_back(sum);
	    }
	    return res;
    }
};
