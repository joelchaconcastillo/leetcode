class Solution(object):
    def solve1(self, s, t):
        return sorted(s) == sorted(t)

    def solve2(self, s, t):
        s_dict = { item:0 for item in s}
        t_dict = { item:0 for item in t }
        for item in s:
            s_dict[item]+=1

        for item in t:
            t_dict[item]+=1
        return s_dict == t_dict

    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return self.solve2(s, t)
