class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
	   sort(digits.begin(), digits.end()); 
	   int n = digits.size();
	   vector<int> res;
	   for(int i = 0 ; i < n; ){
		   for(int j = i+1; j < n ; ){
			   for(int k = j+1; k < n ; ){
				   string  str = "";
				   str += to_string(digits[i]);
				   str += to_string(digits[j]);
				   str += to_string(digits[k]);
				   do{
					   if(str[0]=='0')continue;
					   if(str[0]=='0' && str[1]=='0')continue;
					   if(str[0]=='0' && str[1]=='0' && str[2]=='0')continue;
					   if(stoi(str)%2!=0)continue;
					   res.push_back(stoi(str));
				   }while(next_permutation(str.begin(), str.end()));
				   k = upper_bound(digits.begin(), digits.end(), digits[k])-digits.begin();
			   }
			   j = upper_bound(digits.begin(), digits.end(), digits[j])-digits.begin();
		   }
		   i = upper_bound(digits.begin(), digits.end(), digits[i])-digits.begin();
	   }
	   sort(res.begin(), res.end());
	   return res;
    }
};
