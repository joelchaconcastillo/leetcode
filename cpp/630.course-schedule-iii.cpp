class Solution {
public:
    unordered_map<int, unordered_map<int, int> >memo;
    int helper(vector<vector<int> > &courses, int idx, int time){
	    if(idx == courses.size()){
		    return 0;
	    }
	    if(memo.count(idx) && memo[idx].count(time))return memo[idx][time];
	    int res = 0;
	    //take it
	    int next_time = time+courses[idx][0];
	    if(next_time <= courses[idx][1]){
		    res = max(res, helper(courses, idx+1, next_time)+1);
	    }
	    res = max(res, helper(courses, idx+1, time));
	    return memo[idx][time] = res;
    }
    int solve1(vector<vector<int>>& courses) {//TLE
	    auto comparator = [&](vector<int> &course1, vector<int> &course2){
		    if(course1[1] < course2[1])return true;
		    else if (course1[1]>course2[1])return false;
		    else return course1 < course2;
	    };
	    sort(courses.begin(), courses.end(), comparator);
	    return helper(courses, 0, 0);
    }
    int solve2(vector<vector<int>>& courses) {
	    auto comparator = [&](const vector<int> &course1, const vector<int> &course2){
		    return course1[1] < course2[1];
	    };
	    sort(courses.begin(), courses.end(), comparator);
	    priority_queue<int> pq;
	    int current_time = 0, n = courses.size();
	    for(int i = 0 ; i < n; i++){
		    int duration = courses[i][0] , deadline = courses[i][1];
		    int next_time = duration+current_time;
		    if(next_time <= deadline){
			    pq.push(duration);
			    current_time = next_time;
		    }else if(!pq.empty() && pq.top() > duration){
			    current_time += duration-pq.top();
			    pq.pop();
			    pq.push(duration);
		    }
	    }
	    return pq.size();
    }
    int scheduleCourse(vector<vector<int>>& courses) {
	    return solve2(courses);
    }
};
