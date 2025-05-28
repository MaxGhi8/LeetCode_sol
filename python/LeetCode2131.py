class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        seen = {}
        center_flag = 0
        ans = 0
        for w in words:
            w_pal = w[1] + w[0]
            if seen.get(w_pal, -1) > 0:
                ans += 4
                seen[w_pal] -= 1
                if w[0] == w[1]:
                    center_flag -= 1
            else:
                seen[w] = seen.get(w, 0) + 1
                if w[0] == w[1]:
                    center_flag += 1
        
        print(seen)
        if center_flag > 0:
            return ans + 2
        return ans