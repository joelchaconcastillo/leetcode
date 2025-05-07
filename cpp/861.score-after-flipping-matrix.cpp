class Solution {
public:
    int n, m;
    long long solve(vector<vector<int> > &grid){
	 int n = grid.size(), m = grid[0].size();
	 int score = (1<<(m-1))*n;
	 for(int j = 1; j < m; j++){
	    int countSameBits=0;
	    for(int i = 0 ; i < n; i++){
		if(grid[i][j]==grid[i][0])
			countSameBits++;
	    }
	    countSameBits = max(countSameBits, n-countSameBits);
	    int columnScore = (1<<(m-j-1))*countSameBits;
	    score += columnScore;
	 }
	 return score;
    }
    long long solve2(vector<long long> &numbers){
	long long res = score(numbers);
	bool hasChanged=true;
	while(hasChanged){
		hasChanged=false;
		for(int i = 0 ; i < n; i++){
		   flip_row(numbers[i]);
		   auto new_score = score(numbers);
		   if(new_score>res){
		      res=new_score;
		      hasChanged=true;
		      break;
		   }
		   flip_row(numbers[i]);
		}
		if(hasChanged)continue;
		for(int i = 0 ; i < m; i++){
		   flip_col(numbers, i);
		   auto new_score = score(numbers);
		   if(new_score>res){
		      res=new_score;
		      hasChanged=true;
		      break;
		   }
		   flip_col(numbers, i);
		}
	}
	return res;
    }
    void flip_row(long long &row){
	 int mask = (1LL<<(m))-1;
	 row ^= mask;
    }
    void flip_col(vector<long long> &nums, int col){
	 for(int i = 0 ; i < nums.size(); i++){
	     nums[i] ^= (1<<(m-col-1));
	 }
    }// 1 ^ 1 = 0, 0^1 = 1
    long long score(vector<long long> &numbers){
	   long long sum = 0;
	   for(auto i:numbers)sum+=i;
	   return sum;
    }
    int matrixScore(vector<vector<int>>& grid) {
	n = grid.size(), m = grid[0].size();
	return solve(grid);

	vector<long long> numbers(n);
	for(int i = 0 ; i < n ; i++){
	   long long num = 0;
	   for(int j =0; j < m; j++){
		if(grid[i][j]==1) num |= (1LL<<(m-j-1));
	   }
	   numbers[i]=num;
	}
	return solve2(numbers);
    }
};

