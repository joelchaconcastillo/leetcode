class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        res = []
        idx1 = 0 
        idx2 = 0
        idx3 = 0
        while idx1 < len(arr1) and idx2 < len(arr2) and idx3 < len(arr3):
            if arr1[idx1] == arr2[idx2] and arr1[idx1] == arr3[idx3]:
                res.append(arr1[idx1])
                idx1 +=1
                idx2 +=1
                idx3 +=1
            else:
                if arr1[idx1] < arr2[idx2]:
                    idx1+=1
                elif arr2[idx2] < arr3[idx3]:
                    idx2+=1
                else:
                    idx3+=1
        return res
        
