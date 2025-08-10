class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n = prices.size();
       vector<int> stack, res=prices;
       for(int i= n-1;i  >=0; i--){
	       while(!stack.empty() && stack.back()>prices[i]){
		       stack.pop_back();
	       }
	       if(!stack.empty()){
		       res[i] = prices[i]-stack.back();
	       }
	       stack.push_back(prices[i]);
       }       
       return res;
    }
};
