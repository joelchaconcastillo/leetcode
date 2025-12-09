class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        lazy_sum = {}
        for trip in trips:
            lazy_sum[trip[1]] = lazy_sum.get(trip[1],0)+trip[0]
            lazy_sum[trip[2]] = lazy_sum.get(trip[2],0)-trip[0]
        current = 0
        for i in range(1002):
            current += lazy_sum.get(i, 0);
            if current > capacity:
               return False
        return True
