class Solution {
public:
    const long long MOD = 1e9+7;
    int solve(vector<int> &arr){
        int n = arr.size(), res = 0;
	for(int i = 0 ; i < n ; i++){
	   int minv = INT_MAX;
	   for(int j = i; j <n; j++){
		   minv=min(minv, arr[j]);
		   res = (res+minv)%MOD;
	   }
	}
	return res;
    }
    int solve1(vector<int> &a){
	int n = a.size();
	vector<int> st, left(n,-1), right(n, n);//increasing!
	// 3 1 2 4
	//-1-1 1 2  --> left
	// 1 4 4 4  --> right
	for(int i = 0 ; i < n; i++){
	   while(!st.empty() && a[st.back()] >= a[i])st.pop_back();
	   if(!st.empty()) left[i] = st.back();
	   st.push_back(i);
	}
	st.clear();
	for(int i = n-1; i>=0; i--){
	   while(!st.empty() && a[st.back()] > a[i]) st.pop_back();
	   if(!st.empty()) right[i] = st.back();
	   st.push_back(i);
	}
	long long res = 0;
	for(int i = 0 ; i <n ;i++){
	   long long left_segment = (i-left[i]);
	   long long right_segment = (right[i] - i);
	   long long contribution = (left_segment*right_segment*a[i])%MOD;
	   res = (res+contribution)%MOD;
	} // 3 + 6 + 4 + 4 --> 17
	return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
	    return solve1(arr);
    }
};
/*
 Input: arr = [3,1,2,4]
     3 1 1 1 1 2 2 4
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.


 * */
