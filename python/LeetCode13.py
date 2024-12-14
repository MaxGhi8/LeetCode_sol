class Solution(object):
    def romanToInt(self, s: str) -> int:
        """
        :type s: str
        :rtype: int
        """
        dict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        
        s += "o"
        tot = 0
        for idx, char in enumerate(s[:-1]):
            current_value = dict[char]
            if dict.get(s[idx+1], 0) > current_value:
                tot -= current_value
            else:
                tot += current_value
        return tot

        # tot = 0
        # for prev, succ in zip(s[:-1], s[1:]):
        #     prev_num = dict[prev]
        #     if dict[succ] > prev_num:
        #         tot -= prev_num
        #     else:
        #         tot += prev_num
        # return tot + dict[s[-1]]