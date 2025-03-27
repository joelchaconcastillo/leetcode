import bisect

class Solution(object):
    def solve(self, nums):
        if not nums:
            return 0;
        dp = len(nums)*[1]
        #  1  3  6  7  9  4 10  5  6
        #  1  2  3  4  5  3 6   3  3
        res = 0
        for i in range(0, len(nums)):
            dp[i]=1
            for j in range(0, i):
                if nums[j] >= nums[i]:
                    continue
                dp[i] = max(dp[i], dp[j]+1)
            res = max(res, dp[i])
        return res
    def solve2(self, nums):
        dp = []
        for item in nums:
            idx = bisect.bisect_left(dp, item)
            if idx == len(dp):
                dp.append(item)
            else:
                dp[idx] = item
        return len(dp)

    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #return self.solve(nums)
        return self.solve2(nums)
    """
       Input: nums = [10,9,2,5,3,7,101,18]
                                    i
       


                       1 1 1 1 1 1 1   1
                       1 1 1 2
       Output: 4
       LIS problem
       dp(i) is the max len lower that nums[i]
       dp(i) = dp(j) + 1 where nums[i] > nums[j]
    """
