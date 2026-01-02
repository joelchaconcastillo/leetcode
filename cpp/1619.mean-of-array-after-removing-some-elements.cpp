class Solution {
public:
    double trimMean(vector<int>& arr) {
           sort(arr.begin(), arr.end());	    
	   double sum = 0.0;
	   int n = arr.size(), low = 0.05*n, up = n-0.05*n;
	   for(int i = low; i < up; i++) sum+=arr[i];
	   return sum / (up-low);
    }
};
