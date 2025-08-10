class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
	for(auto num:nums){
		auto tmp=num;
		int sum =0 ;
		while(tmp){
			sum+=tmp%10;
			tmp/=10;
		}
		res=min(res, sum);
	}
	return res;
    }
};
