class Solution {
public:
    unordered_map<int, unordered_map<int, int> > tree;
    int dfs(int level, int pos, int sum=0){
	    int pos_left = 2*pos-1;
	    int pos_right = 2*pos;
	    bool hasLeft = (tree.count(level+1) && tree[level+1].count(pos_left));
	    bool hasRight = (tree.count(level+1) && tree[level+1].count(pos_right));
	    int res =0;
	    sum += tree[level][pos];
	    if(hasLeft) res += dfs(level+1, pos_left, sum);
	    if(hasRight) res += dfs(level+1, pos_right, sum);
	    if(!hasLeft && !hasRight) return sum;
	    return res;
    } 
    // 1: 1 1
    //
    // 2: 4 5   1 2
    // 3: 6 7   3 4
    int solve(vector<int>& nums) {
	    for(auto num:nums){
		    int val = num%10;
		    num/=10;
		    int pos = num%10;
		    num/=10;
		    int lev = num%10;
		    tree[lev][pos] = val;
	    }
	    return dfs(1, 1);
    }
    int pathSum(vector<int>& nums) {
	return solve(nums);
    }
};
