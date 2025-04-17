class Solution {
public:
    vector<int> solve1(int n, vector<int> &sums){
	  multiset<int> _sums, sub_sums_1, sub_sums_2;
	  for(auto i:sums)_sums.insert(i);
	  vector<int> res;
	  while(n--){
	     auto delta = *next(_sums.begin()) - *(_sums.begin());
	     while(!_sums.empty()){
		  int operand = *(_sums.begin());
		  sub_sums_1.insert(operand);
		  sub_sums_2.insert(operand+delta);
		  _sums.erase(_sums.begin());
		  _sums.erase(_sums.find(operand+delta));//remove only one item
	     }
	     if(sub_sums_1.count(0)){
		     swap(_sums, sub_sums_1);// zero indicates that this subset contains the remaining sums
		     res.push_back(delta);
	     }
	     else{ 
		     swap(_sums, sub_sums_2);
		     res.push_back(-delta);
	     }
	     sub_sums_1.clear();
	     sub_sums_2.clear();
	  }
	  return res;
    }
    // a - b -  c - d - e - f
    // c c+k
    void dfs(vector<int> &sums, vector<int> &res){
	    if(sums.size() == 1)return; //it only contains empty set
	    vector<int> sub_sums_1, sub_sums_2;
	    int target_num = sums[1]-sums[0];
	    bool choose_sub_2 = false;
	    unordered_map<int, int>counter;
	    for(auto i:sums)counter[i]++;
	    for(auto &sum:sums){
	       if(counter[sum] == 0)continue;
	       counter[sum]--;
	       counter[sum+target_num]--;
	       sub_sums_1.push_back(sum);
	       sub_sums_2.push_back(sum+target_num);
	       if(sum+target_num == 0) choose_sub_2 = true;
	    }
	    dfs(choose_sub_2?sub_sums_2:sub_sums_1, res);
	    res.push_back(choose_sub_2?-target_num:target_num);
    }
    vector<int> solve2(int n, vector<int> &sums){
	    vector<int> res;
	    sort(sums.begin(), sums.end());
	    dfs(sums, res);
	    return res;
    }
    vector<int> recoverArray(int n, vector<int>& sums) {
	  //return solve1(n, sums);
	  return solve2(n, sums);
    }
};
/*
 Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
 Output: [1,2,-3]

     -3 -2 -1 0 0 1 2 3
Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
Output: [0,-1,4,5]
      -
    -1 -1 0 0 3 3 4 4 4 4 5 5 8 8 9 9
    res = 0, -1 
    d = 0
    s1 --> -1 0 3 4 4 5 8 9 
    s2 --> -1 0 3 4 4 5 8 9
    sums --> -1 0 3 4 4 5 8 9 
    d = 1
    s1   --> -1 3 4 8
    s2   --> -1 0 0 3 4 4 4 5 5 8 9 9
    d = 1
    sums   --> -1 0 0 3 4 4 4 5 5 8 9 9
    s1   --> -1 -1 0 3 3 4 4 5 8 8 9
    s2   --> 0 1 4 5 6 9 10


    


 * */
