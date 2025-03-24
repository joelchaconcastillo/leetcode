class Solution {
public:
	//time: O(n*m)
	//space: O(n*m) --> can be improved
	//elapsed time to solve it: 30 min.
    long long solve(vector<int> &skill, vector<int> &mana){
       int m = skill.size(), n = mana.size();
       vector<vector<long long> > dp(n,vector<long long>(m,0));
       long long cu_time = 0;
       for(int i = 0; i < m; i++) cu_time += skill[i]*mana[0], dp[0][i]=cu_time;
       for(int i = 1; i < n; i++){
	  dp[i][0] = dp[i-1][0]+skill[0]*mana[i];
	  long long time = dp[i][0];
	  for(int j = 1; j < m; j++){
             long long val = skill[j]*mana[i];
	     if(time < dp[i-1][j]) time = dp[i-1][j];
	     time +=val;
	     dp[i][j] = time;
	  }
	  time = dp[i].back();
	  for(int j = m-2; j>=0; j--){
             long long val = skill[j+1]*mana[i];
	     time -=val;
	     dp[i][j] = time;
	  }
       }
       return dp.back().back();
    }
    long long minTime(vector<int>& skill, vector<int>& mana) {
       return solve(skill, mana);	    
    }
};
/*
 skill = [1,5,2,4], mana = [5,1,4,2]
 0, 1*5, 5*5+5, 30 + 5*2, 40+5*4, 60
 (1+5+2+4)*5 --> 12*5 --> 60
 -----------
 12*1 --> 12

Last case:     [3,5,3,9]↩ [1,10,7,3]
Output:        268
Expected:      293
    3   8   11  20
    33  88  11  20
   


 * */
