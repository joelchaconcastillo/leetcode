class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        res = 0
        for i in range(1,n-1):
            if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
                l,r = i-1, i+1
                while l >=0 and arr[l] < arr[l+1]:
                    l-=1
                while r < n and arr[r] < arr[r-1]:
                    r+=1
                res = max(res, r-l-1)
#                i = r-1
        return res
