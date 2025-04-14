class Solution:
    def solve(self, target, nums):
        l=0
        res = float('inf')
        current_sum = 0
        for i in range(len(nums)):
            current_sum += nums[i]
            while l <= i and current_sum >= target:
                res = min(res, i-l+1)
                current_sum -= nums[l]
                l +=1

        if res == float('inf') :
            return 0
        return res

    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        return self.solve(target, nums)
        
