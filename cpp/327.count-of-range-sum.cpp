class Solution {
public:
    vector<long long> prefix;
    int lower, upper;
    int merge(int l, int mid, int r){
	    vector<long long> tmp(r-l);
	    int count = 0, low1=mid, low2=mid;
	    for(int i = l; i < mid; i++){
		    while(low1<r && prefix[low1]-prefix[i] < lower)low1++;
		    while(low2<r && prefix[low2]-prefix[i] <= upper)low2++;
		    count += low2-low1;
	    }
	    int k = 0, i = l, j = mid;
	    while(i<mid && j<r){
		    if(prefix[i] < prefix[j])tmp[k++]=prefix[i++];
		    else tmp[k++] = prefix[j++];
	    }
	    while(i < mid) tmp[k++] = prefix[i++];
	    while(j < r) tmp[k++] = prefix[j++];
	    for(int i = l,j=0; i < r; i++, j++)prefix[i] = tmp[j];
	    return count;
    }
    int merge_sort(int l, int h){
	    if(l+1>=h)return 0;
	    int mid = (l+h)/2;
	    int cont1 = merge_sort(l, mid);
	    int cont2 = merge_sort(mid, h);
	    return cont1+cont2+merge(l, mid, h);
    }
    int solve1(vector<int>& nums, int lower, int upper) {
	    int n = nums.size();
	    prefix.assign(n+1, 0);
	    this->lower = lower;
	    this->upper = upper;
	    for(int i = 0; i <n; i++){ 
		    prefix[i+1] = nums[i]+prefix[i];
	    }
	    return merge_sort(0, prefix.size());
    }
struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n+1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) bit[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int range_query(int l, int r) { // inclusive
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int solve2(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    vector<long long> sums(n+1, 0);
    for (int i = 0; i < n; i++) 
        sums[i+1] = sums[i] + nums[i];

    // coordinate compression
    vector<long long> all = sums;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto getIndex = [&](long long x) {
        return (int)(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1; // 1-based for BIT
    };

    Fenwick ft(all.size());
    long long res = 0;

    // Insert prefix sum 0
    ft.update(getIndex(sums[0]), 1);

    for (int i = 1; i <= n; i++) {
	    // lower <= sums[i]-sums[j-1] <= upper
	    // lower -sums[i] <= -sums[j-1] <= upper-sums[i]
	    // sums[i] - lower >= sums[j-1] >= sums[i] - upper
        long long lo = sums[i] - upper;
        long long hi = sums[i] - lower;
        int left = (int)(lower_bound(all.begin(), all.end(), lo) - all.begin()) + 1;
        int right = (int)(upper_bound(all.begin(), all.end(), hi) - all.begin());
        res += ft.range_query(left, right);
        ft.update(getIndex(sums[i]), 1);
    }

    return (int)res;
}

    int countRangeSum(vector<int>& nums, int lower, int upper) {
	    return solve2(nums, lower, upper);
    }
};
