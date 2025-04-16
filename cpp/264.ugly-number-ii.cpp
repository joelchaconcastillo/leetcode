class Solution {
public:
    // dp[i] = dp[i/k]
    // overkilling!!!!
    int solve3(int n){
	unordered_map<long long, bool> dp;
	vector<long long> _primes = {2,3,5}, res={1};
	dp[1] = true;
	long long i = 2;
	while(res.size() < n){
	   for(auto &k:_primes){
	       if( i%k == 0 && dp[i/k]) dp[i]= dp[i/k];
	   }
	   if(dp[i])res.push_back(i);
	   i++;
	}
	return res.back();
    }
    int solve2(int n) {
      set<long long> s;
      s.insert(1);
      long long res = 1;
      for (int i = 0; i < n; ++i) {
        res = *s.begin();
        s.erase(s.begin());
        s.insert(res * 2);
        s.insert(res * 3);
        s.insert(res * 5);
      }
      return (int)res;
    }
    int solve(int n) {
      unordered_set<long long> marked;
      priority_queue<long long, vector<long long>, greater<long long>> pq;
      vector<long long> options = {2, 3, 5};
      pq.push(1);
      marked.insert(1);
      long long res = 1;
      while (n--) {
        res = pq.top();
        pq.pop();
        for (auto opt : options) {
            long long next = res * opt;
            if (marked.count(next)) continue;
            marked.insert(next);
            pq.push(next);
        }
      }
      return (int)res;
    }
    int nthUglyNumber(int n) {
	//return solve(n);
	//return solve2(n);
	return solve3(n);
    }
};
/*
 *
 Input: n = 10
Output: 12
Explanation: 
[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

 1 2 3 4 5 6  8 9 10 12
 dp(i) = dp(j) 

 */
