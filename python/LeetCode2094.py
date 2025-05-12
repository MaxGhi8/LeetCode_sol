class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        freq = {}
        for d in digits:
            freq[d] = freq.get(d, 0) + 1
        
        result = []
        for first in range(1, 10):
            if first not in freq:
                continue
            freq[first] -= 1
            
            for second in range(10):
                if second not in freq or freq[second] <= 0:
                    continue
                freq[second] -= 1
                
                for last in [0, 2, 4, 6, 8]:
                    if last not in freq or freq[last] <= 0:
                        continue
                    result.append(100 * first + 10 * second + last)
                
                freq[second] += 1
                
            freq[first] += 1
        
        return result