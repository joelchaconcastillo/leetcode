class Solution:
    def count(self, n: int) -> list:
        freq = [0]*10
        while n > 0:
            freq[n%10]+=1
            n//=10
        return freq

    def reorderedPowerOf2(self, n: int) -> bool:
        ref = self.count(n)
        for i in range(31):
            if ref == self.count(1<<i):
                return True
        return False

