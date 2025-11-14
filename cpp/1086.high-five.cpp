class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
         unordered_map<int, priority_queue<int, vector<int>, greater<>> > id_scores;
         for(auto &item:items){
		 id_scores[item[0]].push(item[1]);
		 if(id_scores[item[0]].size() > 5)
			 id_scores[item[0]].pop();
	 }	 
	 vector<vector<int> > res;
	 for(auto [id, pq]:id_scores){
		 int ave = 0;
		 while(!pq.empty()){
			 ave += pq.top();
			 pq.pop();
		 }
		 ave/=5;
		 res.push_back({id, ave});
	 }
	 sort(res.begin(), res.end());
	 return res;
    }
};
