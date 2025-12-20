class Solution {
public:
    //Input: arr = [2,1,4,7,3,2,5]
    //                  i
    //              0 0 1 2 0 0 0
    //              1 0 0 2 1 0 0
    //
    //              left[i]+right[i]-1;
    //Output: 5
    //Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

    int solve(vector<int>& arr) {
	    int n = arr.size();
	    vector<int> dp_left(n), dp_right(n);
	    int res = 0;
	    for(int i = 0 ; i <n ;i++){ // left
		    if(i>0 && arr[i]>arr[i-1]) dp_left[i] = dp_left[i-1]+1;
		    else dp_left[i] = 1;
	    }
	    for(int i = n-1; i >=0 ; i--){
		    if( i+1<n && arr[i]>arr[i+1]) dp_right[i] = dp_right[i+1]+1;
		    else dp_right[i] = 1;
	    }
	    for(int i = 1;i+1<n ; i++){
		    if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
			   res = max(res, dp_left[i-1]+dp_right[i+1]+1);
	    }
	    return res;
    }

    // Input: arr = [2,1,4,7,3,2,5]
    //                     i
    //                 l
    //                         r
    int solve2(vector<int>& arr) {
	    int n = arr.size();
	    int res = 0;
	    for(int i = 1; i+1 < n; i++){
		    if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
			    int l = i-1;
			    while(l>=0 && arr[l] < arr[l+1]) l--;
			    int r = i+1;
			    while(r<n && arr[r] < arr[r-1])r++;
			    res = max(res, r-l-1);
			    i = r-1;
		    }
	    }
	    return res;
    }
    int longestMountain(vector<int>& arr) {
	    return solve2(arr);
	    return solve(arr);
    }
};
