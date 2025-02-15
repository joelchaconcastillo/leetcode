class Solution {
public:
    /*
       time: O(n)
       space: O(n)
     * */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
	 sort(intervals.begin(), intervals.end());
	 intervals.push_back({INT_MAX, INT_MAX});
         vector<vector<int > > res;
	 int n = intervals.size();
	 int _start = intervals[0][0], _end = intervals[0][1];
	 for(int i = 0 ; i < n; i++){
	     if( _end >= intervals[i][0]){ // overlap
		_end = max(_end, intervals[i][1]);
	     }else{
		 res.push_back({_start,_end});
		 _start = intervals[i][0];
		 _end = intervals[i][1];
	     }
	 }

	 return res;
    }
};
/*
      if( e < intervals[i][0]){
         s = intervals[i][0];
	 e = intervals[i][1];
      }else if(e>=intervals
      [[1,3],[2,6],[8,10],[15,18]] --> [[1,6],[8,10],[15,18]]
                            *

      s=15
      e=18

      {1,6}, {8,10} 

s              e
|--------------| 
          |------------|

 * */
