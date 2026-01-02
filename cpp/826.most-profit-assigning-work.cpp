class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	   int n = difficulty.size();
           vector<pair<int, int> > dif_prof(n);
	   for(int i = 0 ; i < n; i++){
		   dif_prof[i] = {difficulty[i], profit[i]};
	   }
	   sort(dif_prof.begin(), dif_prof.end());
	   int max_prof = dif_prof.front().second;
	   vector<int> pref_profit(n,0);
	   for(int i = 0 ; i < n ; i++){
		   max_prof = max(max_prof, dif_prof[i].second);
		   pref_profit[i] = max_prof;
	   }
	   int res = 0;
	   for(auto w:worker){
		   int idx = upper_bound(dif_prof.begin(), dif_prof.end(), make_pair(w, INT_MAX))-dif_prof.begin();
		   if(idx>0){
		     res += pref_profit[idx-1];
		   }
	   }
	   return res;
    }
};
