class Solution {
public:
    vector<int> helper(int n){
	    if(n==1)return {1};
	    vector<int> beaut;
	    for(auto i:helper((n+1)/2)){//odd
		    beaut.push_back(i*2-1);
	    }
	    for(auto i:helper(n/2)){//even
		    beaut.push_back(i*2);
	    }
	    return beaut;
    }
    vector<int> beautifulArray(int n) {
	    return helper(n);
    }
};
// 2*n[k] == n[i]+n[j] iff 0<=i<k<j<n
//
//   
//
