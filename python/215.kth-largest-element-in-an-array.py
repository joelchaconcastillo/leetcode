import heapq

class Solution(object):
    def solve(self, nums, k):
        pq = []

        for item in nums:
            heapq.heappush(pq, item) 
            if len(pq) > k:
                heapq.heappop(pq)
        return pq[0]

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return self.solve(nums, k)
        
