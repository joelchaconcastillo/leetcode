class FenwickTree{
	public:
		int n;
		vector<int> ft;
		FenwickTree(){}
		FenwickTree(int n):n(n){
			ft.assign(n+2,0);
		}
		void insert(int index, int val){
			while(index <= n){
				ft[index]+=val;
				index += index&(-index);
			}
		}
		int query(int index){
			int res = 0;
			while(index>0){
				res += ft[index];
				index -= index&-index;
			}
			return res;
		}
		int query(int l, int r){
			return query(r)-query(l-1);
		}
};
class NumArray {
public:
  //  FenwickTree objFT;
  //  NumArray(vector<int>& nums) {
  //     int n = nums.size();
  //     objFT = FenwickTree(n);
  //     for(int i = 0 ; i < n ;i++){
  //             objFT.insert(i+1, nums[i]);
  //     }
  //  }
  //  
  //  void update(int index, int val) {
  //          int prev = objFT.query(index+1, index+1);
  //          objFT.insert(index+1, val-prev);
  //  }
  //  
  //  int sumRange(int left, int right) {
  //          return objFT.query(left+1, right+1);
  //  }
    int n, size_block;
    vector<int> blocks, nums;

    NumArray(vector<int>& nums) {
	    n = nums.size();
	    this->nums = nums;
	    size_block = max(3, (int)sqrt(n));
	    int num_blocks = ceil(n/(double)size_block);
	    blocks.assign(num_blocks, 0);
	    for(int i = 0; i < n; i++){
		    blocks[i/size_block] += nums[i];
	    }
    }
    
    void update(int index, int val) {
	    int index_block = index/size_block;
	    blocks[index_block] -= nums[index];
	    blocks[index_block] += val;
	    nums[index] = val;
    }
    
    int sumRange(int left, int right) {
	    int left_block = left/size_block, right_block = right/size_block;
	    int sum = 0;
	    if(left_block == right_block){
		    for(int i = left; i<=right; i++)sum+=nums[i];
	    }else{
		    while(left/size_block == left_block) sum += nums[left++];
		    while(right/size_block == right_block) sum+=nums[right--];
		    for(int i = left/size_block; i <= right/size_block; i++){
			    sum +=blocks[i];
		    }
	    }
	    return sum;
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
