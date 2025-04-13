class Solution:
    def solve(self, nums):
        n = len(nums)
        _left = [0]*n
        _right = [0]*n
        _sum = 0
        for i in range(n):
            _left[i] = _sum
            _sum += nums[i]
        _sum = 0
        for i in range(n-1,-1, -1):
            _right[i] = _sum
            _sum += nums[i]
        for i in range(n):
            if _left[i] == _right[i]:
               return i
        return -1


    def pivotIndex(self, nums: List[int]) -> int:
        return self.solve(nums)
        
