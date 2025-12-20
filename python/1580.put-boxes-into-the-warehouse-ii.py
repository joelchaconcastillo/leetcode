class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        boxes.sort()
        left, right = 0, len(warehouse)-1
        res, i = 0, len(boxes)-1
        while left <= right and i>=0:
            if warehouse[left] >= boxes[i]:
                res += 1
                left += 1
            elif warehouse[right] >= boxes[i]:
                res += 1
                right -= 1
            i-=1
        return res

