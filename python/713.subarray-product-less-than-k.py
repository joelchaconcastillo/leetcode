class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        prod, l = 1, 0
        res = 0
        for idx in range(len(nums)):
            prod *= nums[idx]
            while l<=idx and prod >= k:
                prod/=nums[l]
                l+=1
            res += idx-l+1
        return res
