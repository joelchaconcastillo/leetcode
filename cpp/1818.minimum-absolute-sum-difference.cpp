class Solution {
public:
      int solve(vector<int> &nums1, vector<int> &nums2){
	long long sum = 0, max_diff = 0, n = nums1.size();
	auto nums2_sorted = nums1;
	sort(nums2_sorted.begin(), nums2_sorted.end());
	nums2_sorted.erase(unique(nums2_sorted.begin(), nums2_sorted.end()), nums2_sorted.end());
	for(int i = 0 ;i  < n; i++){
	   long long delta = abs(nums1[i]-nums2[i]);
	   sum += delta;
	   auto id = lower_bound(nums2_sorted.begin(), nums2_sorted.end(), nums2[i])-nums2_sorted.begin();
	   if(id < n) max_diff = max(max_diff, delta-abs(nums2[i]-nums2_sorted[id]));
	   if(id>0) max_diff = max(max_diff, delta-abs(nums2[i]-nums2_sorted[id-1]));
	   if(id+1 < n) max_diff = max(max_diff, delta-abs(nums2[i]-nums2_sorted[id+1]));
     
	}
	int MOD = 1e9+7;
	return (sum - max_diff)%MOD;
    }

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
	return solve(nums1, nums2);
    }
};
