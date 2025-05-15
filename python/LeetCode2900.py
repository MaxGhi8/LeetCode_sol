class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        result = []
        bit = -1
        for w, b in zip(words, groups):
            if b != bit:
                result.append(w)
                bit = b

        return result
