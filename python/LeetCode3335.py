class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        update_1 = {
            'a': 'b',
            'b': 'c',
            'c': 'd',
            'd': 'e',
            'e': 'f',
            'f': 'g',
            'g': 'h',
            'h': 'i',
            'i': 'j',
            'j': 'k',
            'k': 'l',
            'l': 'm',
            'm': 'n',
            'n': 'o',
            'o': 'p',
            'p': 'q',
            'q': 'r',
            'r': 's',
            's': 't',
            't': 'u',
            'u': 'v',
            'v': 'w',
            'w': 'x',
            'x': 'y',
            'y': 'z',
            'z': 'ab'
            }
        update_26 = {
            'a': 'ab',
            'b': 'bc',
            'c': 'cd',
            'd': 'de',
            'e': 'ef',
            'f': 'fg',
            'g': 'gh',
            'h': 'hi',
            'i': 'ij',
            'j': 'jk',
            'k': 'kl',
            'l': 'lm',
            'm': 'mn',
            'n': 'no',
            'o': 'op',
            'p': 'pq',
            'q': 'qr',
            'r': 'rs',
            's': 'st',
            't': 'tu',
            'u': 'uv',
            'v': 'vw',
            'w': 'wx',
            'x': 'xy',
            'y': 'yz',
            'z': 'zab'
            }

        # Process the string to dict
        D = {}
        for c in s:
            D[c] = D.get(c, 0) + 1
        
        
        # update
        for _ in range(t // 26):
            D = self.update(D, update_26)
        for _ in range(t % 26):
            D = self.update(D, update_1)
        
        # count
        count = 0
        for key in D:
            count = (count + D[key]) % (10**9 + 7)
        return count 
    
    def update(self, D, update_dict):
        # update function
        new_D = {}
        for key in D:
            for c in update_dict[key]:
                new_D[c] = (new_D.get(c, 0) + D[key]) % (10**9 + 7)
        return new_D

