class Solution {
public:
    string solve(int a, int b, int c){
       priority_queue<tuple<int, char>> pq;
       pq.push({a, 'a'});
       pq.push({b, 'b'});
       pq.push({c, 'c'});
       string res = "";
       while(!pq.empty()){
	     auto [count, letter] = pq.top(); pq.pop();
	     if(count==0)break;
	     if(res.empty() || res.size() == 1){
		res += letter;
		pq.push({count-1, letter});
	     }else{
		int size_res = res.size();
		if( res[size_res-1] == letter && res[size_res-2] == letter){
		   auto [count2, letter2] = pq.top(); pq.pop();
		   if(count2==0)break;
		   res += letter2;
		  pq.push({count, letter});
		  pq.push({count2-1, letter2});
		}else{
		  res += letter;
		  pq.push({count-1, letter});
		}
	     }
       }
       return res;
    }
    string longestDiverseString(int a, int b, int c) {
	return solve(a,b,c);
    }
};
/*
 *
 *
 Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

   (1,a), (1,b), (7,c) 
   (1,a), (1,b), (5,c) --> cc
   (1,a), (0,b), (5,c) --> ccb
   (1,a), (0,b), (3,c) --> ccbcc
   (0,a), (0,b), (3,c) --> ccbcca
   (0,a), (0,b), (1,c) --> ccbccacc
   


Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
  (0,c), (1,b), (7,a)
  (0,c), (1,b), (5,a) --> aa
  (0,c), (0,b), (5,a) --> aab
  (0,c), (0,b), (3,a) --> aabaa

 * */
