class Solution:
    def robotWithString(self, s: str) -> str:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        D = dict()
        t = ""
        ans = ""
        for c in s:
            D[c] = D.get(c, 0) + 1

        i = 0
        while i < len(s):
            # Take the best I can do
            c_min = self.get_min(alphabet, D)

            # Check for t
            if t!="" and t[-1] <= c_min:
                ans += t[-1]
                t = t[:-1]
                continue

            # Find the best in s
            for j in range(i, len(s)):
                c = s[j]
                if c == c_min:
                    ans += c
                    D[c] -= 1
                    i += 1
                    break
                else:
                    t += c
                    D[c] -= 1
                    i += 1
        
        for i in range(len(t) - 1, -1, -1):
            ans += t[i]
        
        return ans

        
    def get_min(self, alphabet:str, D:dict):
        for c in alphabet:
            if D.get(c, 0) > 0:
                return c
        