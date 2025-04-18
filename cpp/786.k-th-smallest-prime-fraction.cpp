class Solution {
public:
    vector<int> solve1(vector<int> &arr, int k){
	 if(arr.empty())return {};
	 int n = arr.size();
	 multiset<tuple<double, int, int>> pq;
	 for(int i = 0  ; i < n; i++){
	    for(int j = i+1; j < n; j++){
		pq.insert({arr[i]/(double)arr[j], arr[i], arr[j]});
		if(pq.size()>k) pq.erase(prev(pq.end()));
	    }
	 }
	 auto [dec, num, den] = *prev(pq.end());
	 return {num, den};
    }
    vector<int> solve2(vector<int> &arr, int k){
	 if(arr.empty())return {};
	 int n = arr.size();
	 priority_queue<tuple<double, int, int>>pq;
	 for(int i = 0 ; i+1<n; i++) pq.push({-arr[i]/(double)arr[n-1], i, n-1});
	 while(--k){
	      auto [dec, num, den] = pq.top();pq.pop();
	      den--;
	      pq.push({-arr[num]/(double)arr[den], num, den});
	 }
	 auto [dec, num, den] = pq.top();
	 return {arr[num], arr[den]};
    }
    vector<int> solve3(vector<int> &arr, int k){
	    double lo=0.0, hi=1.0;
	    int n = arr.size();
	    while(lo<hi){
		 double mid = (lo+hi)/2.0;
		 double max_f = 0.0;
		 int j = 1, countSmaller = 0, den=0, num=0;
		 for(int i = 0; i+1 < n; i++){
		    while(j<n && arr[i] >= arr[j]*mid) j++;
		    countSmaller += (n-j);
		    if(j==n)break;
		    double dec = arr[i]/(double)arr[j];
		    if(dec > max_f){
			 max_f = dec;
			 num = i;
			 den = j;
		    }
		 }
		 if(countSmaller<k)lo=mid;
		 else if(countSmaller>k)hi=mid;
		 else{
		      return {arr[num], arr[den]};
		 }

	    }
	    return {};
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
     //return solve1(arr, k);
     //return solve2(arr, k);
     return solve3(arr, k);
    }
};
/*
 
Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]


 * */
