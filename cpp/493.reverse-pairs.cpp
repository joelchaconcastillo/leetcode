class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r, int &res){
	    int i = l, j = mid;
	    vector<int> tmp(r-l);
	    //counting..
	    for(int z1 = l, z2=mid; z1<mid; z1++){
		    while(z2 < r && (long long)nums[z1] > 2LL*nums[z2])z2++;
		    res += (z2-mid);
	    }
	    int k=0;
	    while(i < mid && j < r ){
		    if(nums[i] < nums[j])tmp[k++]=nums[i++];
		    else tmp[k++] = nums[j++];
	    }
	    while( i < mid)tmp[k++]=nums[i++];
	    while( j < r)tmp[k++]=nums[j++];
	    for(int i = l, j = 0; i<r;i++,j++){
		    nums[i] = tmp[j];
	    }
    }
    void mergeSort(vector<int> &nums, int l, int r, int &res){
	    if(l>=r)return;
	    if(l+1==r)return;
	    int mid = (l+r)/2;
	    mergeSort(nums, l, mid, res);
	    mergeSort(nums, mid, r, res);
	    merge(nums, l, mid, r, res);
    }
    int solve1(vector<int>& nums) {
	    int res = 0;
	    mergeSort(nums,0, nums.size(), res);
	    return res;
    }
    vector<int> FT;
    void insert(int idx, long long val){
	    while(idx >0){
		    FT[idx]+=val;
		    idx -= idx&(-idx);
	    }
    }
    int query(int idx){
	    int res = 0;
	    while(idx<FT.size()){
		    res += FT[idx];
		    idx += idx&(-idx);
	    }
	    return res;
    }
    int solve2(vector<int>& nums) {
	    vector<int> nums_sorted(nums);
	    sort(nums_sorted.begin(), nums_sorted.end());
	    int n = nums.size(), res = 0;
	    FT.assign(n+1,0);
	    for(int i = 0; i<n; i++){
		    int mapped_index_query = lower_bound(nums_sorted.begin(), nums_sorted.end(), 2LL*nums[i]+1)-nums_sorted.begin()+1;
		    res += query(mapped_index_query);
		    int mapped_index_insert = lower_bound(nums_sorted.begin(), nums_sorted.end(), nums[i])-nums_sorted.begin()+1;
		    insert(mapped_index_insert, 1);
	    }
	    return res;
    }
    int reversePairs(vector<int>& nums) {
	    return solve2(nums);
    }
};
