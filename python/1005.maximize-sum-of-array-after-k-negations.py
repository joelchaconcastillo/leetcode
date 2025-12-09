class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()
        i = 0
        while i < len(nums) and k>0 and nums[i] < 0:
            nums[i] = -nums[i];
            i+=1
            k-=1
        k %=2
        if k == 0:
            return sum(nums)
        return sum(nums) - 2*abs(min(nums))
