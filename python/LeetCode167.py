class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        a = 0
        b = len(nums)-1
        while a < 3*(10**4):
            num_1 = nums[a]
            num_2 = nums[b]
            sum_ = num_1 + num_2
            if sum_ < target:
                a += 1
            elif sum_ > target:
                b -= 1
            else:
                return [a+1, b+1]

        return []