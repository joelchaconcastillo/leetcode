class Solution {
public:
    string largestMerge(string word1, string word2) {
	 deque<char> dq1(word1.begin(), word1.end());
	 deque<char> dq2(word2.begin(), word2.end());
	 string res = "";
	 while(!dq1.empty() && !dq2.empty()){
		 if(dq1 > dq2){
			 res += dq1.front();
			 dq1.pop_front();
		 }else{
			 res += dq2.front();
			 dq2.pop_front();
		 }
	 }
	 while(!dq1.empty()){
			 res += dq1.front();
			 dq1.pop_front();

	 }
	 while(!dq2.empty()){
			 res += dq2.front();
			 dq2.pop_front();

	 }
	 return res;
    }
};
