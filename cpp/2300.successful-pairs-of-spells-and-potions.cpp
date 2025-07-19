class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
	    int n = spells.size(), m = potions.size();
	    vector<double> pots;
	    for(auto i:potions) pots.push_back(success/(double)i);
	    sort(pots.begin(), pots.end());
	    vector<int> res;
	    for(auto sp:spells){
		    int idx = upper_bound(pots.begin(), pots.end(), (double)sp)-pots.begin();
		    res.push_back(idx);
	    }
	    return res;
    }
};
