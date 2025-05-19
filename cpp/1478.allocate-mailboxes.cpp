class Solution {
public:
    map<tuple<int, int>, int> memo;
    int min_dist(vector<int> &houses, int k, int lo){
	if(k==0){
	   if(lo==houses.size()) return 0;
	   return 1000000;
	}
	tuple<int, int> key (k, lo);
	if(memo.count(key))return memo[key];
	int res = 1000000;
	for(int i = lo; i < houses.size(); i++){
	    int median = (i-lo+1)/2;
	    int score = 0;
	    for(int j = lo; j <= i; j++)score += abs(houses[lo+median]-houses[j]);
	    res = min(res, min_dist(houses, k-1, i+1)+score);
	}
	return memo[key] = res;
    }
    int solve1(vector<int> &houses, int k){
       memo.clear();
       int n = houses.size();
       sort(houses.begin(), houses.end());
       return min_dist(houses, k, 0);
    }
    int minDistance(vector<int>& houses, int k) {
	    return solve1(houses, k);
    }
};
/*
 
 houses = [1,4,8,10,20], k = 3
    *        *        *   *                              *
    1  2  3  4  5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 1    
 2   
 3 
 O(k*n*n
 * */
