class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	    vector<int> res(n);
	    vector<int> counter(n+2);
	    for(auto book:bookings){
		    counter[book[0]]+=book[2];
		    counter[book[1]+1]-=book[2];
	    }

	    int current = 0 ;
	    for(int i = 0 ; i < n ;i++){
		    current += counter[i+1];
		    res[i] = current;
	    }
	    return res;
    }
};
