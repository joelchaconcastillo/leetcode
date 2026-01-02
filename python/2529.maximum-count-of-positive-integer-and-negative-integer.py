class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        i = bisect.bisect_left(nums, 0)
        j = bisect.bisect_right(nums, 0)
        return max(i, len(nums)-j)

