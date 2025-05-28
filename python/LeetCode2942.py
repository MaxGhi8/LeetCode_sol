class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        ans = []
        for i in range(len(words)):
            w = words[i]
            for c in w:
                if c == x:
                    ans.append(i)
                    break
        return ans
