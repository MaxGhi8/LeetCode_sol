import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        s = s.lower()
        b  = len(s)
        if b <= 1:
            return True
        else:
            a = 0
            b -= 1
            while a < b:
                if s[a] != s[b]:
                    return False
                else:
                    a += 1
                    b -= 1
            return True