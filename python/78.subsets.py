class Solution(object):
    def comb(self, nums, _current, idx, res):
        if idx == len(nums):
            res.append(_current[:])
            return
        self.comb(nums, _current, idx+1, res) # not taking it
        _current.append(nums[idx])
        self.comb(nums, _current, idx+1, res) #taking it
        _current.pop()

    def solve1(self, nums):
        res = []
        self.comb(nums, [], 0, res)
        return res

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.solve1(nums)
        
