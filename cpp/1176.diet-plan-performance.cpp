class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
          int n = calories.size(), score=0, current_sum=0;
	  for(int i = 0 ; i <n; i++){
		  current_sum += calories[i];
		  if(i-k >= 0) current_sum -= calories[i-k];
		  if(i-k+1<0)continue;
		  if(current_sum < lower) score--;
		  else if(current_sum > upper)score++;
	  }
	  // _ _ _ _
	  //   i
	  return score;
    }
};
