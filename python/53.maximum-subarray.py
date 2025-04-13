class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = min(nums)
        _sum = 0
        for i in nums:
            _sum +=i
            res = max(res, _sum)
            _sum = max(0, _sum)
        return res

