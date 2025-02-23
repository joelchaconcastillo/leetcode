class Solution {
public:
    /*
     *  
        time: O(n)
        space: O(1)
     * */
    int thirdMax(vector<int>& nums) {
	  set<int> pq;
	  for(auto i:nums){
	     pq.insert(i);
	     if(pq.size()>3) pq.erase(pq.begin());
	  }
	  if(pq.size()==3)
	    return *(pq.begin());
	  return *prev(pq.end());
    }
};
/*

   2 2 3 1

 * */
