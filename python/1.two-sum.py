class Solution(object):
    def solve(self, nums, target):
        marked = {} # key:num
        for i, num1 in enumerate(nums):
            num2 = target - num1
            if num2 in marked:
                return [i, marked[num2]]
            marked[num1]=i


    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        return self.solve(nums, target)
