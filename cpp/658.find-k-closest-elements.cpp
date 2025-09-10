class Solution {
public:
    
    vector<int> solve1(vector<int>& arr, int k, int x) {
          int id_center = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
	  if(id_center==arr.size())id_center--;
	  if(id_center > 0 && abs(arr[id_center-1]-x) <= abs(arr[id_center]-x)) id_center--;
	  // 1 2 3 4
	  deque<int> res;
	  res.push_back(arr[id_center]);
	  int i = id_center-1, j = id_center+1;
	  while(res.size() < k && i >=0 && j < arr.size()){
		  if(abs(arr[i]-x) <= abs(arr[j]-x)) res.push_front(arr[i--]);
		  else res.push_back(arr[j++]);
	  }
	  while(res.size() < k && i>=0)res.push_front(arr[i--]);
	  while(res.size() < k && j < arr.size())res.push_back(arr[j++]);
	  vector<int> ans(res.begin(), res.end());
	  return ans;

    }
    vector<int> solve2(vector<int>& arr, int k, int x) {
	  int i = 0, j = arr.size()-1;
	  while(j-i+1 > k){
		  if(abs(arr[j]-x) >= abs(arr[i]-x)) j--;
		  else i++;
	  }
	  return vector<int> (arr.begin()+i, arr.begin()+i+k);
    }
    vector<int> solve3(vector<int>& arr, int k, int x) {
	    int lo = 0, hi = arr.size()-k;
	    while(lo<hi){
		    int mid = (lo+hi)/2;
		    if( x-arr[mid] <= arr[mid+k]-x) hi=mid;
		    else lo=mid+1;
	    }
	    return vector<int>(arr.begin()+lo, arr.begin()+lo+k);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	    return solve3(arr, k, x);
    }
};
