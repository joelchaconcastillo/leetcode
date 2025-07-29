class Solution {
public:
    void solve(vector<int> &nums){
	    int n = nums.size();
	    sort(nums.begin(), nums.end());
	    vector<int>res(n);
	    int i=0, j=0;
	    while(i<n){
		    res[i] = nums[j];
		    i+=2;
		    j++;
	    }
	    i=1;
	    while(i<n){
		    res[i] = nums[j];
		    i+=2;
		    j++;
	    }
	    nums=res;
    }
    void solve2(vector<int> &nums){
	    int n = nums.size();
	    unordered_map<int, int> freq;
	    int minv=INT_MAX, maxv=INT_MIN;
	    for(auto item:nums){
		    freq[item]++;
		    minv= min(minv, item);
		    maxv = max(maxv, item);
	    }
	    vector<int> res(n);
	    int j = 0;
	    for(int i = minv; i<=maxv; i++){
		    if(freq.count(i)==0)continue;
		    while(freq[i] > 0){
			    if(j>=n)j=1;
			    res[j] = i;
			    j+=2;
			    freq[i]--;
		    }
	    }
	    nums=res;
    }
    void solve3(vector<int> &nums){
	    int n = nums.size();
	    for(int i = 0; i+1 < n; i++){
		    if(i%2==0 && nums[i] > nums[i+1] )swap(nums[i], nums[i+1]);
		    if(i%2==1 && nums[i] < nums[i+1])swap(nums[i], nums[i+1]);
	    }
    }
    void wiggleSort(vector<int>& nums) {
	    solve3(nums);
//	    solve2(nums);
//	    solve(nums);
    }
};
