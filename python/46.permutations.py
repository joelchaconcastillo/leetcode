class Solution(object):
    permutations = []
    taken = {}

    def back_track(self, idx, nums, path):
        if len(path) == len(nums):
            self.permutations.append(path[:])

        for i in range(len(nums)):
            if self.taken[nums[i]]:
                continue
            self.taken[nums[i]] = True
            path.append(nums[i])
            self.back_track(i, nums, path)
            path.pop()
            self.taken[nums[i]] = False


    def solve1(self, nums):
        self.permutations = []
        self.taken = {i:False for i in nums}
        self.back_track(0, nums, [])
        return self.permutations

    def back_track2(self, idx, nums):
        if idx == len(nums):
           self.permutations.append(nums[:])
           return
        for i in range(idx, len(nums)):
           nums[idx], nums[i] = nums[i], nums[idx]
           self.back_track2(idx+1, nums)
           nums[idx], nums[i] = nums[i], nums[idx]

    def solve2(self, nums):
        self.permutations = []
        self.taken = {i:False for i in nums}
        self.back_track2(0, nums)
        return self.permutations

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.solve2(nums)
