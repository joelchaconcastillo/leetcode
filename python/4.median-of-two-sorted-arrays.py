class Solution:
    def solve(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        n1 = len(nums1)
        n2 = len(nums2)
        N = n1+n2
        median = N//2
        lo, hi = 0, n1
        isOdd = (N%2)
        while lo <= hi:
            m1 = (lo+hi)//2
            m2 = median-m1+isOdd
            left1 = float('-inf') if m1==0 else nums1[m1-1]
            right1 = float('inf') if m1==n1 else nums1[m1]
            left2 = float('-inf') if m2==0 else nums2[m2-1]
            right2 = float('inf') if m2==n2 else nums2[m2]
            if left2 > right1:
                lo = m1+1
            elif left1 > right2:
                hi = m1-1
            else:
                if isOdd:
                    return max(left1, left2)
                else:
                    return (max(left1, left2)+min(right1, right2))/2.0

        return 0


    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        return self.solve(nums1, nums2)
