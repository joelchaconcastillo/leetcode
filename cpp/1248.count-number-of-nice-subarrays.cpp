class Solution {
public:
    int solve3(vector<int> &nums, int k){
	    int n = nums.size(), res = 0, last_removed=-1;
	    queue<int> q;
	    for(int i = 0 ; i < n ;i++){
		    if(nums[i]%2 == 1) q.push(i);
		    while(q.size()>k){
			    last_removed = q.front();q.pop();
		    }
		    if(q.size() == k){
			    res += q.front()-last_removed;
		    }
	    }
	    return res;
    }
    int solve2(vector<int> &nums, int k){
	    int sum = 0, res=0, n = nums.size();
	    unordered_map<int, int> counter;
	    counter[0] = 1;
	    for(int i = 0 ; i <n ;i++){
		    sum += nums[i]%2;
		    res += counter[sum-k];
		    counter[sum]++;
	    }
	    return res;
    }
    int atMost(vector<int> &nums, int k){
	    int n = nums.size();
	    int l = 0, res=0, cnt=0;
	    for(int i =  0 ;i < n; i++){
		    cnt += nums[i]%2;
		    while( l <=l && cnt > k){
			    cnt -=nums[l++]%2;
		    }
		    res += (i-l)+1;
	    }
	    return res;
    }
    int solve(vector<int> &nums, int k) {
	    return atMost(nums, k)-atMost(nums, k-1);
    }
    int solve4(vector<int> &nums, int k){
	    int res = 0, n = nums.size();
	    int l = 0, countOnes = 0, countSpace = 0;
	    for(int i = 0 ;i  <n ;i++){
		    countOnes += nums[i]%2;
		    if(countOnes == k) countSpace=0;//restart prev segment '00001'
		    while(countOnes == k){
			    countSpace++;
			    countOnes-=nums[l++]%2;
		    }
		    res += countSpace;
	    }
	    return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
	    return solve4(nums, k);
	    return solve3(nums, k);
	    return solve2(nums, k);
	    return solve(nums, k);
    }
};
///  1 2 2 1 2 2 2 2 2 1 2 2 2   k= 2
///        l           i
///         *     *
///
///  [2,2,2,1,2,2,1,2,2,2]
///         l
///               i
/// nums = [1,1,2,1,1], k = 3
///           l
///                 i
