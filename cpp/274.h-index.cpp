class Solution {
public:
    int hIndex(vector<int>& citations) {
	    int n = citations.size();
	    vector<int> freq(n+1,0);
	    for(auto h:citations) freq[min(h, n)]++;
	    for(int i = n-1; i>=0; i--) freq[i] += freq[i+1];
	    int maxv  = 0;
	    for(int i = 1; i<=n ;i++){
		    if( i <= freq[i]) maxv = max(maxv, i);
	    }
	    return maxv;
    }
};
//  1 3 1
//
//  1 2 3 4 5
//  0 1 3 5 6
//  5 4 3 2 1
//
//   [100]
//     1
// 
//  [0]
//   0
//
//   1 2 3
//   0 0 1
//   1
