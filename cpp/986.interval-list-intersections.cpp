class Solution {
public:
/*
 *   time: O(n+m log n+m)
 *   space: O(n+m)
 * */
    vector<vector<int> > solve1(vector<vector<int>> &A, vector<vector<int> > &B){
	  vector<vector<int>> tmp = A;
	  for(auto interval:B)tmp.push_back(interval);
	  sort(tmp.begin(), tmp.end());
	  int n = tmp.size();
	  vector<vector<int>> res;
	  int E = tmp[0][1];
	  for(int i = 1 ; i < n; i++){
	     if(tmp[i][0] <= E) res.push_back({tmp[i][0], min(tmp[i][1], E)});
             E = max(E, tmp[i][1]);		  
	  }
	  return res;
    }
/*
 *   time: O(n+m log n+m)
 *   space: O(1)
 * */

    vector<vector<int> > solve2(vector<vector<int>> &A, vector<vector<int> > &B){
       vector<vector<int>>res; 
       int i = 0, j = 0, n = A.size(), m = B.size();
       while(i < n && j < m){
	   int s1=A[i][0], e1=A[i][1], s2=B[j][0], e2=B[j][1];
	   if(e1 < s2) i++;
	   else if(e2 < s1) j++;
	   else{
	     int _start = max(s1, s2), _end = min(e1,e2);
	     res.push_back({_start, _end});
	     if(e1 < e2) i++;
	     else j++;
	   }
       }
       return res;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
//       return solve1(firstList, secondList);
       return solve2(firstList, secondList);
    }
};
/*
     e2<s1
            s1 -- e1
  s2 -- e2
  ______________________
      e1<s2
         s1 -- e1
                     s2 -- e2
  ______________________
  s2<e1  s1<s2
  s1 -- e1
      s2 -- e2
   ______________________
   s1<e2 e2<e1
           s1 -- e1
      s2 -- e2
   ----------------------
      s2 >=s1   e2<=e1
        s1                    e1
	     s2    e2

Last case:          [[10,12],        [18,19]]↩ 
            [[1,6],[8,11]   ,[13,17],   [19,20]]
Output:        [[8,12],[19,19]]
Expected:      [[10,11],[19,19]]
 * */
