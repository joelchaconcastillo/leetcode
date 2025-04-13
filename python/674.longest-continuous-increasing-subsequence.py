class Solution:
    def solve(self, nums):
        res = 1
        current = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                current+=1
            else:
                current = 1
            res = max(res, current)
        return res

    def findLengthOfLCIS(self, nums: List[int]) -> int:
        return self.solve(nums)
        
