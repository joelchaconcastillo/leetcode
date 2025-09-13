class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
	    int n = intervals.size();
	    vector<vector<int> > by_start_idx;
	    for(int i = 0 ; i < n; i++){
		    by_start_idx.push_back({intervals[i][0], i});
	    }
	    sort(by_start_idx.begin(), by_start_idx.end());
	    vector<int> res(n, -1);
	    for(int i = 0 ; i < n; i++){
		    vector<int> marker = {intervals[i][1], -1};
		    int idx_start = lower_bound(by_start_idx.begin(), by_start_idx.end(), marker)-by_start_idx.begin();
		    if(idx_start >=n)continue;
		    res[i] = by_start_idx[idx_start][1];
	    }
	    return res;
    }
};

/*

   Input: intervals = [[3,4],[2,3],[1,2]]
                         
    

   Output: [-1,0,1]
   1) sort it by starting index
       [1,2](2), [2,3](1), [3,4](0)
          1         0       -1
   2) monotonic decreasing on end

   Input: intervals = [[1,4],[2,3],[3,4]]
                 i
       [1,4](0), [2,3](1), [3,4](2)
                   2              i
        [1,4], 

   Output: [-1,2,-1]

    (2,3)-1,(1,4)-0,(3,4)-2
      i
    (2,3), 

   |-------|
       |---------------|
             |-------|
                           |-------|
    
 *
 * **/
