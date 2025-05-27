class Solution {
public:
    vector<int> solve(vector<vector<int> > &tasks){
	 int n = tasks.size();
	 typedef tuple<int, int, int> mytype;
	 priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
	 vector<mytype> tasks2;
	 vector<int>res(n, 0);
	 for(int i = 0 ; i < n; i++)tasks2.push_back({tasks[i][0], tasks[i][1], i});
	 sort(tasks2.begin(), tasks2.end());
	 int current_time=0, i=0, cnt=0;
	 while(i < n){
	     auto [eT, pT, idx] = tasks2[i];
	     if(eT <= current_time){
		 pq.push({pT,idx});
		 i++;
		 continue;
	     }
	     if(!pq.empty()){
		 auto [pT, idx] = pq.top(); pq.pop();
		 current_time += pT;
		 res[cnt++] = idx;
		 continue;
	     }
	     current_time = eT;
	 }
	 while(!pq.empty()){
		 auto [pT,idx] = pq.top();pq.pop();
		 res[cnt++] = idx;
	 }
	 return res;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
       return solve(tasks);    
    }
};
/*
 [
    [1,2],
    [2,4],
    [3,2],
    [4,1]]

  


 * */
