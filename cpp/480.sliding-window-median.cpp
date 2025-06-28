class Solution {
public:
   double get_median(set<pair<int, int> > &_left, 
	  set<pair<int, int> > &_right, int k){
	        if(k%2!=0) return (_left.rbegin()->first);
		return ((double)_left.rbegin()->first+
					_right.begin()->first)/2.0;
   }
   void balance(set<pair<int, int> > &_left, 
	   set<pair<int, int> > &_right){
	   _right.insert(*_left.rbegin());
	   _left.erase(prev(_left.end()));
	   if(_left.size() < _right.size()){
		   _left.insert(*_right.begin());
		   _right.erase(_right.begin());
	   }
   }
    vector<double> solve(vector<int> &nums, int k){
	    set<pair<int, int>> _left, _right;
	    int n = nums.size();
	    vector<double> res;
	    int i = 0;
	    for(; i < k; i++){
		    _left.insert({nums[i], i});
	            balance(_left, _right);
	    }
	    res.push_back(get_median(_left, _right, k));
	    int l = 0;
	    for(; i < n; i++){//n=1, i=0
		_left.insert({nums[i], i});
		_left.erase({nums[l], l});
		_right.erase({nums[l], l});
		l++;
		balance(_left, _right);
	        res.push_back(get_median(_left, _right, k));
	    }
	    return res;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
