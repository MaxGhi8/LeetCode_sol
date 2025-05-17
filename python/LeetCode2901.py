class Solution:
    def getWordsInLongestSubsequence(
        self, words: List[str], groups: List[int]
    ) -> List[str]:
        n = len(words)
        dp = [1] * n
        prev = [-1] * n
        max_index = 0

        for i in range(1, n):
            for j in range(i):
                if self.checkHamming(words[i], words[j]) and groups[i] != groups[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        prev[i] = j
                    if dp[i] > dp[max_index]:
                        max_index = i

        result = []
        i = max_index
        while i > -1:
            result.append(words[i])
            i = prev[i]
        result.reverse()
        return result

    def checkHamming(self, v: str, w: str) -> bool:
        return self.hammingDistance(v, w) == 1

    def hammingDistance(self, v: str, w: str) -> int:
        if len(v) != len(w):
            return -1
        distance = 0
        for c, s in zip(v, w):
            if c != s:
                distance += 1
        return distance
