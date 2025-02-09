class Solution {
public:
    int maxDifference(string s) {
       unordered_map<char, int> counter;
       for(auto i:s) counter[i]++;
       int minv = INT_MAX, maxv = INT_MIN;
       for(auto ii:counter){
	      if(ii.second%2==1) maxv = max(maxv, ii.second);
	      else minv = min(minv, ii.second);
       }
       return maxv-minv;
    }
};
