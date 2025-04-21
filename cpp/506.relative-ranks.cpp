class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       int n = score.size();
       vector<pair<int, int>>places;
       for(int i = 0 ; i < n; i++) places.push_back({score[i], i});
       sort(places.begin(), places.end(), [](const pair<int, int> &a, const pair<int, int> &b){
		           return a>b;
		       });
       vector<string> res(n, "");
       if(n==0)return {};
       res[places[0].second] = "Gold Medal";
       if(n==1) return res;
       res[places[1].second] = "Silver Medal";
       if(n==2) return res;
       res[places[2].second] = "Bronze Medal";
       if(n==3) return res;
       for(int i = 3; i < n; i++) res[places[i].second]=to_string(i+1);
       return res;
    }
};
