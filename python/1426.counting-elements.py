class Solution:
    def countElements(self, arr: List[int]) -> int:
        freq = {}
        for item in arr:
            freq[item] = freq.get(item,0)+1
        res = 0
        for (val, count) in freq.items():
            if (val+1) in freq:
                res += count
        return res
