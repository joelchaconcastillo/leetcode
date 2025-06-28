class Solution {
public:
    int eval(vector<int> &stations, double min_dist){
	    int n = stations.size();
	    int needed_k = 0;
	    for(int i = 0; i+1 < n; i++){
		    double delta = stations[i+1]-stations[i];
		    needed_k += max((int)ceil(delta/min_dist)-1,0);
	    }
	    return needed_k;
    }
    double solve(vector<int> &stations, int k){
	    double lo = 0.1, hi = stations.back()-stations.front()+1;
	    while( abs(hi-lo) > 1e-6 ){
		 double m = (lo+hi)/2.0;
		 int needed_k = eval(stations, m);
		 /// lo - - - - - mid - - - - - hi
		 ///       n_k
		 /// lower needed_k huge dist -> decrease dist
		 /// lager needed_k very small dist  --> increase dist;
		 if(needed_k <= k){  //decrease delta
			 hi = m;
		 }else{
			 lo = m+1e-6;
		 }
	    }
	    return lo;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
	    return solve(stations, k);
    }
};
