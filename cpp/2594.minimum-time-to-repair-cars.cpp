class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, long long> > > memo;

    long long dp(vector<int> &ranks, int idx, int rem_cars, long long max_score){
	 if(rem_cars < 0 )return INT_MAX;
	 if( idx == ranks.size()){
		if(rem_cars == 0) return max_score;
		return INT_MAX;
	 }
	 if(memo.count(idx) && memo[idx].count(rem_cars) && memo[idx][rem_cars].count(max_score))return memo[idx][rem_cars][max_score];
	 long long res = INT_MAX;
	 for(int i = 0; i <= rem_cars; i++){
	    res = min(res, dp(ranks, idx+1, rem_cars-i, max(max_score,1LL*i*i*ranks[idx])));
	 }
	 return memo[idx][rem_cars][max_score] = res;
    }
    long long solve2(vector<int> &ranks, int cars){
	 return dp(ranks, 0, cars, 0);
    }

    long long solve1(vector<int> &ranks, int cars){
	 set<tuple<long long, long long, long long, int> > pq;
	 map<int, int>counter;
	 for(auto i:ranks)counter[i]++; //compress repeated ranks
	 for(auto ii:counter) pq.insert({0, ii.first, 0, ii.second});
	 long long res = 0;
	 while( cars > 0){
	      auto [time, rank, n_cars, freq]= *pq.begin();
	      pq.erase({time,rank, n_cars, freq});
	      n_cars++;
	      if(time) cars -= freq;
	      res = time;
	      pq.insert({ rank*n_cars*n_cars,rank, n_cars, freq});
	 }
	 return res;
    }
    long long repairCars(vector<int>& ranks, int cars) {
	 //return solve2(ranks, cars);
	 return solve1(ranks, cars);
    }
};
/*
 Input: ranks = [4,2,3,1], cars = 10
 Output: 16
   10 cars

   4 2 3 1
   0 0 0 0

   n*n*r
   greedy?
   dp?
   dp[i][j] = min(dp[i][j], dp[i-1][j-ranks[])
     0  1  2   3   4   5   6   7   8  9   10
   4 0  4  16    
   3 0
   2 0
   1 0
 * */
