class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        minEndLand = min([landStartTime[i]+landDuration[i] for i in range(len(landStartTime))])
        minEndWater = min([waterStartTime[i]+waterDuration[i] for i in range(len(waterStartTime))])
        landWater = min([  max(minEndLand, waterStartTime[i]) + waterDuration[i] for i in range(len(waterStartTime))])
        waterLand = min([max(minEndWater, landStartTime[i]) + landDuration[i] for i in range(len(landStartTime))  ])
        return min(landWater, waterLand)
