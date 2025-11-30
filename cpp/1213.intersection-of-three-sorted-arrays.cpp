class Solution {
public:
    vector<int> solve(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
	    vector<int> res;
	    auto it2 = arr2.begin();
	    auto it3 = arr3.begin();
	    for(auto num:arr1){
		   it2 = lower_bound(it2, arr2.end(), num);
		   it3 = lower_bound(it3, arr3.end(), num);
		 if( it2!=arr2.end() && it3 != arr3.end()){
			 if( *it2==num && *it3 == num)res.push_back(num);
		 }
	    }
	    return res;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
	    return solve(arr1, arr2, arr3);
    }
};
