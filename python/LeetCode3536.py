class Solution:
    def maxProduct(self, n: int) -> int:
        As = [int(i) for i in str(n)]
        n1 = max(As)
        As.remove(n1)
        n2 = max(As)
        return n1*n2
        