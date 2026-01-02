class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unplaced = len(fruits)
        for fruit in fruits:
            for i in range(len(baskets)):
                if fruit <= baskets[i]:
                    unplaced -= 1
                    baskets[i] = 0
                    break
        return unplaced
