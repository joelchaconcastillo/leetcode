class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
	 vector<int> res(num_people, 0);
	 int j = 0, i=1;
	 while(candies){
		 int rem = min(candies, i);
		 res[j%num_people] += rem;
		 candies -=rem;
		 j++;
		 i++;
	 }
	 return res;
    }
};
