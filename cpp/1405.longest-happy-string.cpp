class Solution {
public:
    string solve(int a, int b, int c){
	   priority_queue<tuple<int, char>> pq;
	   if(a>0) pq.push({a, 'a'});
	   if(b>0) pq.push({b, 'b'});
	   if(c>0) pq.push({c, 'c'});
	   string res = "";
	   while(!pq.empty()){
		 auto [counter, letter] = pq.top(); pq.pop();
		 if(!res.empty() && letter == res.back()){
		   if(pq.empty())break;
		   auto [counter2, letter2] = pq.top(); pq.pop();
		   res += letter2;
		   counter2--;
		   pq.push({counter, letter});
		   if(counter2>0){
		     pq.push({counter2, letter2});
		   }
		 }else{
		     res += letter;
		     counter--;
		     if(counter==0)continue;
		     pq.push({counter, letter});
		 }
	   }
	   return res;
    }
    string longestDiverseString(int a, int b, int c) {
	return solve(a,b,c);
    }
};
/*
 Input: a = 1, b = 1, c = 7
 a b c
 0 0 3
 i
 ccbccacc

Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

     

 * */
