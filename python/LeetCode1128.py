class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        D = {}
        for dom in dominoes:
            key = (min(dom[0], dom[1]), max(dom[0], dom[1]))
            D[key] = D.get(key, 0) + 1

        count = 0
        for v in D.values():
            count += (v * (v-1)) // 2
        
        return count

        