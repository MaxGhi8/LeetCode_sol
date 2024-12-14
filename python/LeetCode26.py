class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        while True:
            try:
                if nums[i] == nums[i - 1]:
                    nums.pop(i)
                else:
                    i += 1
            except:
                return i
