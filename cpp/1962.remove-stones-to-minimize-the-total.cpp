class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int> pq;
       for(auto i:piles)pq.push(i);
       while(k){
	 auto current = pq.top();pq.pop();
	 pq.push(ceil(current/2.0));
	 k--;
       }
       int sum = 0 ;
       while(!pq.empty()){
	     sum +=pq.top(); pq.pop();
       }
       return sum;
    }
};
/*
  4  3  6  7, k =3
  3 4 6 7
  3 4 4 6
  3 3 4 4
  2 3 3 4


 * */
