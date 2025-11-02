class Solution {
public:
    bool solve(vector<int>& nums, int indexDiff, int valueDiff) {
         multiset<int> values;
         int n = nums.size();
	 int k = indexDiff;
         for(int i = 0 ; i < n; i++){
		 auto it = values.lower_bound(nums[i]);
		 if(it != values.end() && *it-nums[i] <= valueDiff)return true;
		 if( it!=values.begin()){
			 it--;
			 if(nums[i]-*it<=valueDiff)return true;
		 }
		 values.insert(nums[i]);
		 if(i>=k){
		      auto it = values.find(nums[i-k]);
		      values.erase(it);
		 }
	 }	 
	 return false;

    }
































    bool solve2(vector<int>& nums, int indexDiff, int valueDiff) {
	 int n = nums.size(), l = 0;
	 multiset<int> values;
	 for(int i = 0 ;i < n; i++){
		 auto it = values.lower_bound(nums[i]);
		 if(it != values.end())
			 if(abs(*it -  nums[i])<=valueDiff)return true;
		 if(it!=values.begin()){
				 it--;
			         if(abs(*it -  nums[i])<=valueDiff)return true;
		}
		 if(!values.empty() && i-l+1>indexDiff){
		   values.erase(values.find(nums[l++]));
		 }
		 values.insert(nums[i]);
	 }
	 return false;
    }
    int indexDiff, valueDiff;
    bool merge(vector<pair<int, int>> &nums, int l, int mid, int r){
	    vector<pair<int ,int>> tmp;
	     int lo = mid, hi = mid;
	     for(int i = l; i < mid; i++){
		 while(lo < r &&  nums[i].first-nums[lo].first > valueDiff) lo++;
		 while(hi < r &&  nums[hi].first-nums[i].first <= valueDiff) hi++;

		 for(int k = lo; k < hi; k++){
		     if(abs(nums[k].second-nums[i].second) <= indexDiff)return true;
		 }
	     }
	    int i=l, j = mid, k=0;
	    while(i<mid && j<r){
		    if(nums[i].first < nums[j].first){
			 tmp.push_back(nums[i++]);
		    }else{
			 tmp.push_back(nums[j++]);
		    }
	    }
	    while(i  < mid) tmp.push_back(nums[i++]);
	    while(j < r) tmp.push_back(nums[j++]);
	    for(int  i = l, j=0; i < r; i++, j++){
		    nums[i] = tmp[j];
	    }
	    return false;
    }
    bool mergeSort(vector<pair<int, int>> &nums, int l, int r){
	 if(l+1>=r)return false;
	 int mid = (l+r)/2;
	 bool res = false;
	 if( mergeSort(nums, l, mid) || mergeSort(nums, mid, r))
		 return true;
	 return merge(nums, l, mid, r);
    }
    bool solve3(vector<int>& nums, int indexDiff, int valueDiff) {
	 this->indexDiff = indexDiff;
	 this->valueDiff = valueDiff;
	 vector<pair<int, int> > nums2;
	 for(int i = 0 ; i < nums.size(); i++){
		 nums2.push_back({nums[i],i});
	 }
//	 sort(nums2.begin(), nums2.end());
	 return mergeSort(nums2, 0, nums.size());
    }
    int get_bucket_id(int idx, int w){
	    return (idx<0)?((idx+1)/w)-1:idx/w;
    }
    bool solve4(vector<int>& nums, int indexDiff, int valueDiff) {
	    if( valueDiff < 0 ) return false;
	    unordered_map<long, long> buckets;
	    long w = valueDiff+1;
	    int n = nums.size();
	    for(int i = 0; i < n; i++){
		    long current_bucket = get_bucket_id(nums[i], w);
		    if(buckets.count(current_bucket))return true;
		    if(buckets.count(current_bucket-1)
				    && abs(nums[i]-buckets[current_bucket-1])<=valueDiff) return true;
		    if(buckets.count(current_bucket+1)
				    && abs(nums[i]-buckets[current_bucket+1])<=valueDiff) return true;
		    buckets[current_bucket] = nums[i];
		    if(i>=indexDiff)
			    buckets.erase(get_bucket_id(nums[i-indexDiff], w));
	    }
	    return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
	    return solve4(nums, indexDiff, valueDiff);
	    return solve3(nums, indexDiff, valueDiff);
	    return solve2(nums, indexDiff, valueDiff);

    }
};
//    0 1 2 3
//    1 2 3 1   indexdif = 3, valueDiff ==0
//          i
//    l
//    1,0 1,3 2,1 3,2
//

























