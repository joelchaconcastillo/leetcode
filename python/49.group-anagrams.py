class Solution(object):
    def solve1(self, strs):
        groups = {}
        for _str in strs:
            _sorted = ''.join(sorted(_str))
            if _sorted not in groups:
                groups[_sorted] = [_str]
            else:
                groups[_sorted].append(_str)
        return list(groups.values())

    def solve2(self, strs):
        pass

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        return self.solve1(strs)
