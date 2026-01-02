class Solution:
    def badSensor(self, sensor1: List[int], sensor2: List[int]) -> int:
        i, n = 0, len(sensor1)
        while i < n and sensor1[i] == sensor2[i]:
            i+=1
        if i == n:
            return -1
        res1 = sensor1[i+1:] == sensor2[i:-1]
        res2 = sensor1[i:-1] == sensor2[i+1:]
        if res1 == res2:
            return -1
        if res1:
            return 2
        return 1
