class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        n = len(nums)
        _right = list(reversed(list(accumulate(reversed(nums[1:] + [0])))))
        for i in range(n):
            if _right[i] == _sum:
                return i
            _sum += nums[i]
        return -1
