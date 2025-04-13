class Solution:
    def solve(self, nums):
        res = 0
        for item in nums:
            res ^=item
        return res

    def singleNumber(self, nums: List[int]) -> int:
        return self.solve(nums)
        
