class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        L = len(haystack)
        for i in range(L):
            flag = 0
            for j, c in enumerate(needle):
                if i + j >= L:
                    flag += 1
                    break
                if c != haystack[i + j]:
                    flag += 1
                    break
            if flag == 0:
                return i
        return -1
