class Solution {
public:
    int solve2(vector<int>& arr, int target) {
        unordered_map<int, long long> freq;
        for (int num : arr) freq[num]++;
        const int mod = 1e9 + 7;
        long long res = 0;
        for (auto [num1, cnt1] : freq) {
            for (auto [num2, cnt2] : freq) {
                int rem = target - num1 - num2;
                if (!freq.count(rem)) continue;
                if (!(num1 <= num2 && num2 <= rem)) continue;
                long long cnt3 = freq[rem];
                if (num1 == num2 && num2 == rem) 
                    res += cnt1 * (cnt1 - 1) * (cnt1 - 2) / 6;
                else if (num1 == num2 && num2 != rem) {
                    res += cnt1 * (cnt1 - 1) / 2 * cnt3;
                else if (num1 < num2 && num2 == rem) 
                    res += cnt2 * (cnt2 - 1) / 2 * cnt1;
                else if (num1 < num2 && num2 < rem) 
                    res += cnt1 * cnt2 * cnt3;
                res %= mod;
            }
        }
    
        return (int)res;
    }
    int threeSumMulti(vector<int>& arr, int target) {
	    return solve2(arr, target);
    }
    int solve1(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        int n = arr.size();
	int res = 0, mod = 1e9+7;
        for(int i = 0 ;i  < n; i++){
		for(int j = i+1; j < n; j++){
			int rem = target-arr[i]-arr[j];
			res = (res+freq[rem])%mod;
		}
		freq[arr[i]]++;
	}	
	return res;
    }
};
