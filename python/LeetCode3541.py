class Solution:
    def maxFreqSum(self, s: str) -> int:
        Ds = {}
        for char in s:
            Ds[char] = Ds.get(char, 0) + 1
            
        max_voc = 0
        max_cons = 0
        for k in Ds:
            if k in ['a', 'e', 'i', 'o', 'u']:
                if Ds[k] > max_voc:
                    max_voc = Ds[k]
            else:
                if Ds[k] > max_cons:
                    max_cons = Ds[k]
                    
        return max_voc + max_cons