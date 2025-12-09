class Solution {
public:
// [[4,3,4],[3,2,4],[1,8,9],[7,2,5]]↩ 14
//  1,8,9  3,2,4  4,3,4  7,2,5
//          8-9     :1
//  2--4            :3
//    34            :4
//  2---5           :7
//    

    bool solve2(vector<vector<int>>& trips, int capacity) {
	    int n = trips.size();
	    vector<pair<int ,int> > sum;
	    for(auto &trip:trips){
		    sum.push_back({trip[1], trip[0]});
		    sum.push_back({trip[2], -trip[0]});
	    }
	    sort(sum.begin(), sum.end());
	    int current = 0;
	    for(auto [interval, val]:sum){
		    current += val;
		    if(current > capacity)return false;
	    }
	    return true;
    }
    bool solve1(vector<vector<int>>& trips, int capacity) {
         unordered_map<int, int> sum;
         for(auto trip:trips){
	    sum[trip[1]] += trip[0];
	    sum[trip[2]] -= trip[0];
	 }
	 int total = 0;
	 for(int i = 0 ; i <= 1000; i++){
		 total += sum[i];
		 if(total > capacity)return false;
	 }
	 return true;

    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
	 return solve2(trips, capacity);
	 return solve1(trips, capacity);
    }
};
