class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
         boxes.sort()
         res = 0
         j = len(boxes)-1
         for space in warehouse:
             while j >=0 and boxes[j] > space:
                 j-=1
             if j >=0:
                 res+=1
                 j-=1
         return res
