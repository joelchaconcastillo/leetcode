class Solution {
public:
    double improvement(int num, int den){
	   return (double)(num+1)/(double)(den+1) - (double)num/(double)den;
    }
    double solve(vector<vector<int> > &classes, int extraStudents){
	   priority_queue<tuple<double, int, int>>pq;//delta num den
	   for(auto i:classes){
	       pq.push({ improvement(i[0], i[1]) ,i[0], i[1]});
	   }
	   while(extraStudents--){
		auto [delta, num, den] = pq.top(); pq.pop();
	        pq.push({ improvement(num+1, den+1),num+1, den+1});

	   }
	   int n = classes.size();
	   double res = 0.0;
	   while(!pq.empty()){
		auto [delta, num, del] = pq.top(); pq.pop();
		res += (double)num/del;
	   }
	   return res/n;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
	   return solve(classes, extraStudents);
    }
};
