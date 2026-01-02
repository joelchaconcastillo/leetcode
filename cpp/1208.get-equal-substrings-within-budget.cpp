class Solution {
public:
    bool isFeasible(string &s, string &t, int len, int maxCost){
	    int cost = 0, l=0,  n=s.size();
	    for(int i = 0 ; i < n; i++){
		    cost += abs(s[i]-t[i]);
		    if(i-l+1>len){
			    cost-= abs(s[l]-t[l]);
			    l++;
		    }
		    if(i-l+1==len && cost <= maxCost)return true;
	    }
	    return false;
    }
    int solve1(string s, string t, int maxCost) {
        int lo = 0, hi = t.size();
        while(lo < hi){
		int mid = (lo+hi)/2;
		if(isFeasible(s,t,mid, maxCost)) lo=mid+1;
		else hi=mid;
	}	
	if(!isFeasible(s,t,lo,maxCost)) return lo-1;
	return lo;
    }
    int solve2(string s, string t, int maxCost) {
	int l = 0, n = s.size();
	int res = 0, cost=0;
	for(int i = 0 ; i < n; i++){
		cost += abs(s[i]-t[i]);
		while(l<=i && cost>maxCost){
			cost -= abs(s[l]-t[l]);
			l++;
		}	
		res = max(res, i-l+1);
	}
	return res;
    }
    int equalSubstring(string s, string t, int maxCost) {
	    return solve2(s,t,maxCost);
    }
};
