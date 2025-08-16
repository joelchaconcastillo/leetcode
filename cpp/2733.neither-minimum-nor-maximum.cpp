class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
       int minv = *min_element(nums.begin(), nums.end());
       int maxv = *max_element(nums.begin(), nums.end());
       for(auto i:nums) if(i!=minv && i!=maxv)return i;
       return -1;
    }
};
