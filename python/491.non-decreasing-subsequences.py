class Solution:
    # time: O(2^n * n)
    # space: O(n)
    def dfs(self, nums, idx, current, res):
        if len(current) > 1:
            res.append(current.copy())
        marked = set()
        for _id in range(idx, len(nums)):
            if nums[_id] in marked:
                continue
            if (len(current) == 0 or current[-1] <= nums[_id] ):
              current.append(nums[_id])
              self.dfs(nums, _id+1, current, res)
              current.pop()
              marked.add(nums[_id])


    def solve(self, nums: List[int]):
        res = []
        current = []
        self.dfs(nums, 0, current ,res)
        return res

    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        return self.solve(nums)
        
