class Solution {
public:

    // 1 1 100    2 200
    // 1 
    //
    //
    // if f(i) < f(j) i++
    // else swap(f(i), f(j)) j++;

    // 1 4 5   2 5 8
    //
    // i  
    //   j
    void merge(vector<int> &nums, int start, int mid, int end){
	    int i = start, j = mid;
	    vector<int> tmp;
	    while( i < mid && j < end){
		    if(nums[i] < nums[j]) tmp.push_back(nums[i++]);
		    else tmp.push_back(nums[j++]);
	    }
	    while( i < mid) tmp.push_back(nums[i++]);
	    while(j < end)tmp.push_back(nums[j++]);
	    for(int ii = start, jj=0; ii < end; ii++) nums[ii] = tmp[jj++];
    }
    void merge_sort(vector<int> &nums, int start, int end){
	 if(end-start==1)return;//we don't neet to sort one item
	 int mid = (start+end)/2;
	 merge_sort(nums,start, mid);
	 merge_sort(nums,mid, end);
	 merge(nums, start, mid, end);
    }
    vector<int> solve1(vector<int> &nums){
	    merge_sort(nums, 0, nums.size());
	    return nums;
    }
    int partition(vector<int> &nums, int start, int end){
	    int pivotIndex = start + rand() % (end - start); 
	    swap(nums[pivotIndex], nums[end-1]);
	    int pivot = nums[end-1];
	    int k = start;
	    for(int i = start; i+1 < end; i++){
		    if(nums[i] < pivot) 
			    swap(nums[k++], nums[i]);
	    }
	    swap(nums[k], nums[end-1]);//locate pivot correctly
	    return k;
    }
    void quick_sort(vector<int> &nums, int start, int end){
	    if(start+1 >= end)return;
	    int pivot = partition(nums, start, end);
	    quick_sort(nums, start, pivot);
	    quick_sort(nums, pivot+1, end);
    }
    vector<int> solve2(vector<int>& nums) {
	    quick_sort(nums, 0, nums.size());
	    return nums;
    }
    vector<int> sortArray(vector<int>& nums) {
	    return solve2(nums);
	    return solve1(nums);
    }
};
