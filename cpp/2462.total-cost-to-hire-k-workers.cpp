class Solution {
public:
    long long solve(vector<int> &costs, int k, int candidates){
       long long res = 0;
       int n = costs.size();
       int l = 0, r = n-1;
       set<pair<int, int>> _left, _right;
       for(int i = 0 ; i < k; i++){
         while(l<=r && _left.size() < candidates) _left.insert({costs[l], l++});
         while(l<=r && _right.size() < candidates) _right.insert({costs[r], r--});
	 if( _left.size() && _right.size()){
	    if(*(_left.begin()) < *(_right.begin())){
	       res += _left.begin()->first;
	       _left.erase(_left.begin());
	    }else{
	       res += _right.begin()->first;
	       _right.erase(_right.begin());
	    }
	 }else if(_left.size()){
	       res += _left.begin()->first;
	       _left.erase(_left.begin());
	 }else if(_right.size()){
	       res += _right.begin()->first;
	       _right.erase(_right.begin());
	 }
       }
       cout <<res <<endl;
       return res;
    }
    long long totalCost(vector<int>& costs, int k, int candidates) {
	return solve(costs, k, candidates);
    }
};
