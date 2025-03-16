class Solution {
public:
    /*
     
        time: O(n)
        space: O(1)
	elapsed time to solve: 10 min.
     *
     * */
    //Boyer moore
    vector<int> optimal_solution(vector<int> &nums){
	 vector<int> res;
	 int cont1=0, cont2=0, major1=0, major2=0, n = nums.size();
	 for(auto num:nums){
	    if(num == major1)cont1++;
	    else if(num == major2)cont2++;
	    else if(cont1==0) major1=num, cont1++;
	    else if(cont2==0) major2=num, cont2++;
	    else cont1--, cont2--;
	 }
	 cont1=cont2=0;
	 for(auto num:nums){
	     if(num == major1)cont1++;
	     else if(num == major2)cont2++;
	 }
	 if(cont1 > n/3)res.push_back(major1);
	 if(cont2 > n/3)res.push_back(major2);
	 return res;
    }
    vector<int> solve(vector<int> &nums){
	int n = nums.size();
	unordered_map<int, int> counter;
	for(auto i:nums)counter[i]++;
	vector<int> res;
	int threshold = n/3;
	for(auto ii:counter){
	   if(ii.second > threshold) res.push_back(ii.first);
	}
	return res;
    }
    vector<int> majorityElement(vector<int>& nums) {
       return optimal_solution(nums);
    }
};
/*
   1) we only have at maximum three numbers
   2)

   3,2,3  count(a[i]) > floor(n/3)
   1/3 + 1/3 + 1/3
   n/3
                           
    1 2 3 1 2 3 1 2 3 --> 1 1 1 1 2 2 2 2 3
    


    *   *     *       *     
   |--------|--------|---------|
    3 2 3 | 3 2 3  |  3 2 3
   
   1 2 3 4 1 1 8 9 0
   time O(n)
   space O(1)
 * */
