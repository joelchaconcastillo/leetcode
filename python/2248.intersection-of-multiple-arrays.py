class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        freq = {}
        for row in nums:
            for num in row:
                freq[num] = freq.get(num, 0)+1
        res = [ key  for key,val in freq.items() if val == len(nums)]
        res.sort()
        return res
