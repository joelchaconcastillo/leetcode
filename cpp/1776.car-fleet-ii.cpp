class Solution {
public:

    vector<double> solve(vector<vector<int> > &cars){
	    int n = cars.size();
	    vector<double> res(n, -1.0);
	    vector<int> st;
	    for(int i = n-1; i >=0; i--){
		    while(!st.empty()){
		       if(cars[st.back()][1] >= cars[i][1])st.pop_back();
		       else{
			       double time = (cars[st.back()][0]-cars[i][0])/static_cast<double> (cars[i][1]-cars[st.back()][1]);
			       if( res[st.back()] != -1 && time > res[st.back()]){
				       st.pop_back();
			       }else{
				       res[i] = time;
				       break;
			       }
		       }
		    }
		    st.push_back(i);
	    }
	    return res;
    }
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
	    return solve(cars);
    }
};
//https://leetcode.com/problems/car-fleet-ii/solutions/6868025/c-easy-explanation-with-example///
