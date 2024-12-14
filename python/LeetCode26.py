class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ## This version in not optimized due to the pop operation
        # i = 1
        # while True:
        #     try:
        #         if nums[i] == nums[i - 1]:
        #             nums.pop(i)
        #         else:
        #             i += 1
        #     except:
        #         return i

        ## This version is optimized (without pop operation)
        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i + 1
