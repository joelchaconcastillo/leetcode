class Solution(object):
    def solve(self, nums, k):
        counter = { item:0 for item in nums }
        for item in nums:
            counter[item]+=1
        counter_sorted = []
        for key, val in counter.items():
            counter_sorted.append([val, key])

        res = []
        k_count = 0
        for key, val in sorted(counter_sorted, reverse=True):
            if k_count >= k :
                break
            res.append(val)
            k_count+=1
        return res

    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        return self.solve(nums, k)
        
