class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        for i in range(len(strs[0])):
            char = strs[0][i]
            flag = 0
            for string in strs:
                try:
                    if string[i] != char:
                        flag += 1
                        break
                except Exception:
                    flag += 1
                    break
            if flag == 0:
                result += char
            else:
                break
        return result