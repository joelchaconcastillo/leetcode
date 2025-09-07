class Solution {
public:
    int next(int idx, vector<int> &nums){
	    int n = nums.size();
	    return (idx+nums[idx]+n)%n;
    }
    bool solve1(vector<int>& nums) {
	 int n = nums.size();
	 for(auto &num:nums) num %=n;
	 for(int i = 0 ; i < n ;i++){
		 if(nums[i]==0)continue;
		 int slow = i, fast = i;
		 bool direction = nums[i]>0;
		 while(true){
			 int next_slow = next(slow, nums);
			 if((nums[next_slow]>0) != direction || next_slow == slow) break;
			 int next_fast = next(fast, nums);
			 if((nums[next_fast]>0) != direction || next_fast == fast) break;
			 int next_fast_fast = next(next_fast, nums);
			 if((nums[next_fast_fast]>0) != direction || next_fast == next_fast_fast) break;
			 slow = next_slow;
			 fast = next_fast_fast;
			 if(slow==fast) return true;
		 }
		 int idx = i;
		 while(nums[idx]!=0 && (nums[idx]>0)==direction){
			 int nxt = next(idx, nums);
			 nums[idx]=0;
			 idx=nxt;
		 }
	 }
	 return false;

    }
    bool dfs(vector<int>& nums, int start, vector<int>& visited, bool direction) {
        int n = nums.size();
        if (visited[start] == 2) return false;
        if ((nums[start] > 0) != direction) return false;
        if (visited[start] == 1) return true;
        visited[start] = 1;
        int next = ((start + nums[start]) % n + n) % n;
        if (next == start) {
            visited[start] = 2;
            return false;
        }
        bool result = dfs(nums, next, visited, direction);
        visited[start] = 2;
        return result;
    }
    bool solve2(vector<int>& nums) {
	int n = nums.size();
	vector<int> visited(n, 0);
	for(int i = 0 ; i < n; i++){
		if(visited[i]==0){
			if(dfs(nums, i, visited, nums[i]>0))return true;
		}
	}
	return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
	    return solve2(nums);
	    return solve1(nums);
    }
};
