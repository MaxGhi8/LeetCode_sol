class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maximum = 0
        L = len(s)
        idx = 0
        pc = 1
        while idx < L:
            if pc == 1:
                letters = set(s[idx])
                cc = pc
            else:
                letters = set(s[idx:idx+pc-1])
                cc = pc-1

            while (idx + cc < L) and (s[idx + cc] not in letters):
                letters.add(s[idx + cc])
                cc += 1
                
            idx += 1
            pc = cc
            if cc > maximum:
                maximum = cc


        return maximum