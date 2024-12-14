class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict_nums = {num: idx for idx, num in enumerate(nums)}
        for idx, num in enumerate(nums):
            if dict_nums.get(num, -1) == idx:
                dict_nums.pop(num)
            if (target-num) in dict_nums:
                return [idx, dict_nums[target-num]]