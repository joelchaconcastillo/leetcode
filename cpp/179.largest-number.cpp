class Solution {
public:
    string solve(vector<int> & nums){
       int n = nums.size();
       vector<string> sts;
       for(auto i:nums)sts.push_back(to_string(i));
       sort(sts.begin(), sts.end(),[](const string &a, const string &b){
	  return (a+b> b+a);
	  });
          if(sts[0]=="0" && sts.size()>1)return "0";
	  string res = "";
	  for(auto i:sts){
	    res += i;
	  }
	  if(res.size()>1 && res.front()=='0')return "0";
	  return res;
    }
    string largestNumber(vector<int>& nums) {
       return solve(nums);	    
    }
};
