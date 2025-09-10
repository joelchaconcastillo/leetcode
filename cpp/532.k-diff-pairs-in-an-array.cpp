class Solution {
public:
    int solve1(vector<int> &nums, int k){
	unordered_map<int, unordered_map<int, bool> > marked;
	unordered_set<int> exist;
	for(auto i:nums){
	    if(exist.count(i+k)){
		    marked[min(i,i+k)][max(i, i+k)]=true;
	    }
	    if(exist.count(i-k)){
		    marked[min(i,i-k)][max(i, i-k)]=true;
	    }
	    exist.insert(i);
	}
	int res =0 ;
	for(auto pp:marked){
		res += pp.second.size();
	}
	return res;

    }
    int solve2(vector<int>& nums, int k) {
	unordered_map<int, int> freq;
	for(auto num:nums)freq[num]++;
	int res = 0;
	for(auto [num, cont]:freq){
		if(freq.count(num+k)){
			if(k==0 && freq[num]==1)continue;
		       	res++;
		}
	}
	return res;
    }
    int solve3(vector<int>& nums, int k) {
	    sort(nums.begin(), nums.end());
	    int res = 0, i = 0, j=0, n = nums.size();
	    while(i<n && j <n){
		    int diff = nums[j]-nums[i];
		    if(diff < k)j++;
		    else if( diff > k) i++;
		    else{
			    if(k!=0) res++;
			    int num = nums[i], cont=0;
			    while(i<n && num==nums[i])i++, cont++;
			    if(k==0 && cont>1)res++;
		    }
	    }
	    return res;
    }
    int findPairs(vector<int>& nums, int k) {
	return solve3(nums, k);
    }
};

//  Input: nums = [3,1,4,1,5], k = 2
//                 1 3 4 5
//             3:1   
//             1:1  
//             4:1
//             res=2
//  Output: 2
