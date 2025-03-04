class Solution {
public:
    /*
     *  time: O(n+m)
     *  space: O(n+m)
     *  elapsed time: 5 min.
     * */
    void solve(vector<int> &nums1, int m, vector<int> &nums2, int n){
	 vector<int> res(m+n);
	 int i = 0, j = 0, k=0;
	 while(i < m && j < n){
	    if( nums1[i] < nums2[j])res[k++]=nums1[i++];
	    else res[k++]=nums2[j++];
	 }
	 while(i < m) res[k++]=nums1[i++];
	 while(j < n) res[k++]=nums2[j++];
	 for(int i = 0 ; i < nums1.size(); i++)nums1[i]=res[i];
    }
    /*
       time: O(n+m)
       space: O(1)
     * */
    void solve1(vector<int> &nums1, int m, vector<int> &nums2, int n){
	reverse(nums1.begin(), nums1.begin()+m);
	int i = m-1, j = 0, k=n+m-1;
	while(i>=0 && j < n){
	   if(nums1[i]<=nums2[j]) nums1[k--] = nums1[i--];
	   else nums1[k--] = nums2[j++]; 
	}
	while(j<n) nums1[k--] = nums2[j++];
	reverse(nums1.begin(), nums1.end());
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       solve1(nums1, m, nums2, n); 
    }
};
/*
  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
   
  6 5 3 3 2 1
          i
        k
  6 5 2
      j

  2 4 6 8 0 0 0
  1 3 7
        
  8 7 6 2 6 4 2
              i
          k
  7 3 1
    j
  [1,2,3,0,0,0]↩ 3↩ 
  
  [2,5,6]
 * */
