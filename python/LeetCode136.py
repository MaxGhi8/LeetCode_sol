class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        # D = dict()
        # for num in nums:
        #     D[num] = D.get(num, 0) + 1
        #     if D[num] > 1:
        #         D.pop(num)

        # ls = [i for i in D.keys()]
        # return ls[0]

        result = 0
        for num in nums:
            result ^= num
        return result