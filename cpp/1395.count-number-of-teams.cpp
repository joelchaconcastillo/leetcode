class Solution {
public:
    vector<int> ft;
    void insert(int index, int val){
	    while(index < ft.size()){
		    ft[index]+=val;
		    index += index&(-index);
	    }
    }
    int search(int index){
	    int res = 0;
	    while(index){
		    res += ft[index];
		    index -= index&(-index);
	    }
	    return res;
    }
    int search(int l, int r){
	    return search(r)-search(l-1);
    }
    int compute_incresing_contributions(vector<int> &rating){
	    int n = rating.size();
	    ft.assign(1e5+1,0);
	    vector<int> left_smaller(n, 0), right_greater(n, 0);
	    for(int i = 0 ;i < n ;i++){
		    left_smaller[i] = search(rating[i]-1);
		    insert(rating[i], 1);
	    }
	    ft.assign(1e5+1,0);
	    for(int i = n-1;i >=0 ;i--){
		    right_greater[i] = search(rating[i]+1, ft.size()-1);
		    insert(rating[i], 1);
	    }
	    int res = 0;
	    for(int i = 1; i+1<n;i++){
		    res += left_smaller[i]*right_greater[i];
	    }
	    return res;
    }
    int solve3(vector<int> &rating){
	    auto val1 = compute_incresing_contributions(rating);
	    reverse(rating.begin(), rating.end());
	    auto val2 = compute_incresing_contributions(rating);
	    return val1+val2;
    }
    int solve(vector<int> &rating){
	    int n = rating.size();
	    vector<int> lower(n, 0);//lower on the right
	    for(int i = 0; i < n; i++){
		    for(int j = i+1; j < n; j++){
			    if(rating[i] > rating[j])lower[i]++;
		    }
	    }
	    int res = 0;
	    for(int i = 0 ;i  < n ;i++){
		    for(int j = i+1; j<n; j++){
			    if(rating[i]>rating[j]) res += lower[j];
		    }
	    }
	    return res;
    }


    int solve2(vector<int> &rating){
	    int res = 0, n = rating.size();
	    for(int i = 0 ; i < n; i++){
		    for(int j = i+1 ;j  < n; j++){
			    for(int k = j+1; k < n; k++){
				    if(rating[i] > rating[j] && rating[j] > rating[k])res++;
				    if(rating[i] < rating[j] && rating[j] < rating[k])res++;
			    }
		    }
	    }
	    return res;
    }
    int numTeams(vector<int>& rating) {
	    //O(nlogn)
	    return solve3(rating);
	    //O(n^2)
	    auto v1 = solve(rating);
	    reverse(rating.begin(), rating.end());
	    auto v2 = solve(rating);
	    return v1+v2;
	    //O(n^3)
	    //return solve(rating);
    }
};

/*
 *   *   * *
     2 5 3 4 1
     0 1 1 2 0


     1
     
 *
 *
 * */
