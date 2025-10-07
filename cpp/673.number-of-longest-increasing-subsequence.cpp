class Solution {
public:
    int solve1(vector<int>& nums) {
       int n = nums.size();
       pair<int, int> res(0,0);
       vector<int> dp(n, 1), count(n, 1);
       unordered_map<int, int>freq;
       for(int i = 0 ; i < n; i++){
	       for(int j = 0; j < i; j++){
		       if(nums[i] > nums[j]){
			       if(dp[i] < dp[j]+1){
				       dp[i] = dp[j]+1;
				       count[i] = count[j];
			       }else if(dp[i] == dp[j]+1){
				       count[i] += count[j];
			       }
		       }
	       }
	       freq[dp[i]]+=count[i];
	       res = max(res, {dp[i], count[i]});
       }
       return freq[res.first];
    }
    vector<pair<int, int>> ST;
    pair<int, int> query(int idx, int L, int R, int qL, int qR){
	    if( R<qL || L>qR) return {0,0};
	    if( L>=qL && R<=qR){
		    return ST[idx];
	    }
	    int mid = (L+R)/2;
	    auto resL = query(idx*2, L, mid, qL, qR);
	    auto resR = query(idx*2+1, mid+1, R, qL, qR);
	    if(resL.first > resR.first) return resL;
	    else if(resL.first < resR.first)return resR;
	    return {resL.first, resR.second+resL.second};
    }
    void update(int idx, int L, int R, int pos, pair<int, int> val){
	    if( pos < L || pos > R)return;
	    if(L==R){
		    if(val.first > ST[idx].first) ST[idx] = val;
		    else if(val.first == ST[idx].first) ST[idx].second+=val.second;
		    return;
	    }
	    int mid = (L+R)/2;
	    if(pos <= mid) update(idx*2, L, mid, pos, val);
	    else update(idx*2+1, mid+1, R, pos, val);
	    auto left = ST[idx*2], right = ST[idx*2+1];
	    if(left.first > right.first)ST[idx] = left;
	    else if(left.first < right.first)ST[idx] = right;
	    else ST[idx] = {left.first, left.second+right.second};
    }
    int solve2(vector<int>& nums) {
	    //path compression
	    vector<int> nums2 = nums;
	    sort(nums2.begin(), nums2.end());
	    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
	    int n = nums2.size();
	    ST.assign(4*n, make_pair(0,0));
	    for(int i = 0 ; i < nums.size() ;i++){
		    int idx = lower_bound(nums2.begin(), nums2.end(), nums[i])-nums2.begin();
		    pair<int, int> res;
		    if(idx == 0) res = {0,1};
		    else res = query(1, 0, n-1,0, idx-1);//len, count
		    pair<int, int> newVal = {res.first+1, res.second};
		    update(1,0,n-1,idx, newVal);
	    }
	    return query(1,0, n-1, 0, n-1).second;
    }
    int findNumberOfLIS(vector<int>& nums) {
	    return solve2(nums);
    }
};
// Input: nums = [1,3,5,4,7]
// Output: 2
//
//  1 3 4 7
//  1 1 2 2
//
