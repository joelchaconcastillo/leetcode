class FoodRatings:


    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisine2foods = {}
        self.food2rating = {}
        self.food2cuisine = {}

        for i in range(len(foods)):
            self.food2rating[foods[i]] = ratings[i]
            self.food2cuisine[foods[i]] = cuisines[i]
            if cuisines[i] not in self.cuisine2foods:
                self.cuisine2foods[cuisines[i]] = sortedcontainers.SortedSet()
            self.cuisine2foods[cuisines[i]].add((-ratings[i], foods[i]))


    def changeRating(self, food: str, newRating: int) -> None:
        cuisine = self.food2cuisine[food]
        self.cuisine2foods[cuisine].remove((-self.food2rating[food], food))
        self.food2rating[food] = newRating
        self.cuisine2foods[cuisine].add((-self.food2rating[food], food))


    def highestRated(self, cuisine: str) -> str:
        return self.cuisine2foods[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
