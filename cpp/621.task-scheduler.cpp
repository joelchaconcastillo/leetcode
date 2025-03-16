class Solution {
public:
    /*
        time: O(n log t) where n is the highest frequency and t cooling period, therefore O( n ), since t is a constant 
        space: O(n log n)
     * */
    int solve(vector<char> &tasks, int n){
	priority_queue<pair<int, char>> pq;
	unordered_map<char, int> freq;
	for(int i  = 0; i < tasks.size(); i++){
		freq[tasks[i]]++;
	}
	for(auto ii:freq){
		pq.push({ii.second, ii.first});
	}
	unordered_map<char, int> lastSeen;
	for(auto ii:freq) lastSeen[ii.first] = -100;
	vector<char> res;
        while(!pq.empty()){
	   vector<pair<int, char>> tmp;
	   while(!pq.empty() && res.size() - lastSeen[pq.top().second] <= n){ // A _ A _, res.size = 3, lastS[A] = 2, n = 1
		   tmp.push_back(pq.top());
		   pq.pop();
	   }
	   if(!pq.empty()){
		auto current = pq.top(); pq.pop();
		lastSeen[current.second] = res.size();
	        res.push_back(current.second);
		current.first--;
		if(current.first > 0) pq.push(current);
	   }else{
		res.push_back(' ');
	   }
	   for(auto ii:tmp) pq.push(ii); 
	}	
	return res.size();
    }
    int leastInterval(vector<char>& tasks, int n) {
	return solve(tasks, n);
    }
};
/*
 ["A","C","A","B","D","B"], n = 1
    A  C  A  B  D  B
    A - 4
    B - 2
    C - 1
    D - 1
 ________________________________

 A _ _ A _ _ A
 A _ A _ A
 1) max f is large
  A _ _ A _ _ A _ _ A

 2) max f is not large
 A - 3
 B - 3
 C - 3
 D - 3
 A,2   B,2  C,3  D,3


 A B C D _ 
------
 A - 3
 1 - 1
 2 - 1
 3 - 1
 4 - 1
 5 - 1
 6 - 1

 A 1


 A _ 
 ________________________________

 - We can not locate less spaces than max (freq-1) * n + max freq
 * */
