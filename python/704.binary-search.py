class Solution(object):
    def solve(self, nums, target):
        lo = 0
        hi = len(nums)-1
        while lo <= hi:
            mid = (lo+hi)/2
            if nums[mid] > target:
                hi = mid-1
            elif nums[mid] < target:
                lo = mid+1
            else: 
                return mid
        return -1
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return self.solve(nums, target)
        
