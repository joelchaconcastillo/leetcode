class Solution {
public:
    int solve(vector<int> &weight){
	    int n = weight.size(), res = 0;
	    long long sum = 0;
	    sort(weight.begin(), weight.end());
	    int  i = 0 ;
	    while(i < n && sum+weight[i] <= 5000){
		    sum += weight[i];
		    res++;
		    i++;
	    }
	    return res;
    }
    int maxNumberOfApples(vector<int>& weight) {
	    return solve(weight);
    }
};
